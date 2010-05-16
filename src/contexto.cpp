#include <map>
#include <cctype>

#include "contexto.h"
#include "lista_procedimentos.h"

namespace tiny {

/* ========================================================================== */

/* Construtor */
Contexto::Contexto() 
{
} 

/* ========================================================================== */

/* Destrutor
 * Esvazia as variáveis */
Contexto::~Contexto()
{
	this->variaveis_globais.clear();
}

/* ========================================================================== */

/* obtemVariavel
 * retorna o valor da variável 'nomeVar' */
double Contexto::obtemVariavel(char nomeVar )
{
	if ( isalpha(nomeVar) )
	{
		std::map<char,double>::iterator it;

		/* Primeira Tentativa: Variável Local */
		if ( !pilha_chamada.empty() )
		{
			it = pilha_chamada.top().find(nomeVar);
			if (it != pilha_chamada.top().end()) 
				return it->second;
		}
		
		/* Segunda Tentativa: Variável Global */
	    it = variaveis_globais.find(nomeVar);
		if ( it != variaveis_globais.end() ) 
			return it->second;
		else throw Erro("\nVariável inexistente: "+nomeVar);
	}
	else
		throw Erro("\nVariável inválida: "+nomeVar);
}

/* ========================================================================== */

/* defineVariavel
 * atribui 'valor' à variável 'nomeVar' */
void Contexto::defineVariavel(char nomeVar, double valor)
{
	if ( isalpha(nomeVar) )
	{
		/* Primeira Tentativa: Variáveis locais */
		if ( !pilha_chamada.empty() )
		{
			Variaveis& vars = pilha_chamada.top();
			if ( vars.find(nomeVar) != vars.end() )
			{
				vars[nomeVar] = valor;
				return;
			}
		}
		
		/* Segunda Tentativa: Variáveis Globais */
		if ( variaveis_globais.find(nomeVar) != variaveis_globais.end() )
			variaveis_globais[nomeVar] = valor;
		else 
			throw Erro("\nVariável inexistente: "+nomeVar);
	}
	else
		throw Erro("\nVariável inválida: "+nomeVar);
}

/* ========================================================================== */

void Contexto::adicionaVariavel(char nomeVar, double valor)
{
	if ( isalpha(nomeVar) )
	{
		std::pair<char,double>  new_var(nomeVar,valor);
		bool OK = false;

		/* Primeira Tentativa: Variáveis Locais */
		if ( !pilha_chamada.empty() )
		{
			OK = pilha_chamada.top().insert(new_var).second;
			if (OK) return;
			else throw Erro("\nVariável já existe: "+nomeVar); 
		}

		/* Segunda Tentativa: Variáveis Globais */
		OK = variaveis_globais.insert(new_var).second;
		if ( !OK ) throw Erro("\nVariável global já existe: "+nomeVar);
	} 
	else 
		throw Erro("\nVariável inválida: "+nomeVar);
}

/* ========================================================================== */

void Contexto::adicionaRA()
{
	Variaveis v;
	pilha_chamada.push(v);
}

/* ========================================================================== */

void Contexto::removeRA()
{
	pilha_chamada.pop();
}

/* ========================================================================== */

Procedimento * Contexto::obtemProcedimento(std::string nome_procedimento) {
		
	std::map<std::string, Procedimento *>::iterator it;

	it = this->procedimentos_do_prog->find(nome_procedimento);
	if (it != this->procedimentos_do_prog->end()) 
	{
		return it->second;
	}
	else
	{
		throw Erro("\nNão foi possível encontrar procedimento "+nome_procedimento);
	}
}

/* ========================================================================== */

void Contexto::defineProcedimentos(Procedimentos * procedimentos_do_prog) {
	this->procedimentos_do_prog = procedimentos_do_prog;
}

/* ========================================================================== */

} /* namespace tiny */

