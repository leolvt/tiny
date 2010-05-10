# Makefile para Interpretador de Tiny
# Disciplina de Programação Modular
# Curso de Ciência da Computação - 2010/1
# Universidade Federal de Minas Gerais

CXX = g++
LEX = flex
BISON = bison

CXXFLAGS = -g -Wall
LFLAGS = 
BFLAGS = --defines="src/parser.h"

OBJDIR = bin/obj
BINNAME = bin/tiny

PARAM = 

OBJS = ${OBJDIR}/main.o ${OBJDIR}/scanner.o ${OBJDIR}/parser.o \
	   ${OBJDIR}/driver.o ${OBJDIR}/contexto.o \
	   ${OBJDIR}/exp_aritmetica.o ${OBJDIR}/fator.o \
	   ${OBJDIR}/lista_comandos.o ${OBJDIR}/comando_for.o \
	   ${OBJDIR}/comando_write.o ${OBJDIR}/comando_read.o \
	   ${OBJDIR}/comando_atribuicao.o ${OBJDIR}/boolean.o \
	   ${OBJDIR}/exp_booleana.o ${OBJDIR}/exp_relacional.o \
	   ${OBJDIR}/comando_if.o ${OBJDIR}/comando_while.o \
	   ${OBJDIR}/lista_expressoes.o ${OBJDIR}/lista_variaveis.o

ARCHIVE_FILES = src/ doc/ bin/ Makefile README
ARCHIVE_NAME = tiny.tar.gz

# =============

.PHONY: clean archive run valgrind dir all 

# =============

all: ${BINNAME}

archive: all
	@rm -rf ${ARCHIVE_NAME}
	@echo "Compactando TP"
	@tar -czf ${ARCHIVE_NAME} ${ARCHIVE_FILES}
	@rm -rf archive

clean:
	@rm -fr ${OBJDIR}/*
	@rm -fr ${BINNAME}
	@rm -fr src/scanner.cpp src/parser.h src/parser.cpp
	@rm -rf src/*.hh tags

run: all
	@echo "Executando: "
	@echo "======================"
	@./${BINNAME} ${PARAM}
	@echo "======================"

valgrind: all
	@echo "Executando Valgrind: "
	@echo "======================"
	@valgrind ./${BINNAME} ${PARAM}
	@echo "======================"

dir:
	@mkdir -p ${OBJDIR}

# =============

${BINNAME}: dir ${OBJS}
	@mkdir -p ${OBJDIR}
	@echo "Gerando ${BINNAME}!!"
	@${CXX} ${CXXFLAGS} ${OBJS} -o ${BINNAME}

${OBJDIR}/main.o: src/main.cpp
	@echo "Compilando Modulo Principal"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/contexto.o: src/contexto.cpp src/contexto.h
	@echo "Compilando Modulo Contexto"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/lista_variaveis.o: src/lista_variaveis.cpp src/lista_variaveis.h
	@echo "Compilando Modulo Lista de Variáveis"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/lista_expressoes.o: src/lista_expressoes.cpp src/lista_expressoes.h
	@echo "Compilando Modulo Lista de Expressões"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/lista_comandos.o: src/lista_comandos.cpp src/lista_comandos.h
	@echo "Compilando Modulo Lista de Comandos"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/comando_for.o: src/comando_for.cpp src/comando_for.h
	@echo "Compilando Modulo Comando For"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/comando_if.o: src/comando_if.cpp src/comando_if.h 
	@echo "Compilando Modulo Comando If"
	@${CXX} ${CXXFLAGS} -c $< -o $@
	
${OBJDIR}/comando_while.o: src/comando_while.cpp src/comando_while.h 
	@echo "Compilando Modulo Comando While"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/comando_atribuicao.o: src/comando_atribuicao.cpp src/comando_atribuicao.h
	@echo "Compilando Modulo Comando Atribuição"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/comando_read.o: src/comando_read.cpp src/comando_read.h
	@echo "Compilando Modulo Comando Read"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/comando_write.o: src/comando_write.cpp src/comando_write.h
	@echo "Compilando Modulo Comando Write (writeStr, writeVar, writeln)"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/fator.o: src/fator.cpp src/fator.h
	@echo "Compilando Modulo Fator" 
	@${CXX} ${CXXFLAGS} -c $< -o $@
	
${OBJDIR}/boolean.o: src/boolean.cpp src/boolean.h 
	@echo "Compilando Modulo boolean"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/exp_aritmetica.o: src/exp_aritmetica.cpp src/exp_aritmetica.h
	@echo "Compilando Modulo Expressao Aritmetica" 
	@${CXX} ${CXXFLAGS} -c $< -o $@
	
${OBJDIR}/exp_booleana.o: src/exp_booleana.cpp src/exp_booleana.h
	@echo "Compilando Modulo Expressao Booleana" 
	@${CXX} ${CXXFLAGS} -c $< -o $@
	
${OBJDIR}/exp_relacional.o: src/exp_relacional.cpp src/exp_relacional.h 
	@echo "Compilando Modulo Expressão Relacional"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/driver.o: src/driver.cpp src/driver.h 
	@echo "Compilando Modulo Driver"
	@${CXX} ${CXXFLAGS} -Wno-parentheses -c $< -o $@

${OBJDIR}/scanner.o: src/scanner.cpp src/scanner.h src/parser.cpp
	@echo "Compilando Scanner"
	@${CXX} ${CXXFLAGS} -Wno-parentheses -c $< -o $@

${OBJDIR}/parser.o: src/parser.cpp src/parser.h
	@echo "Compilando Parser"
	@${CXX} ${CXXFLAGS} -Wno-parentheses -c $< -o $@

src/parser.cpp: src/parser.yy
	@echo "Gerando Parser"
	@$(BISON) $(BFLAGS) $< -o $@

src/scanner.cpp: src/scanner.ll
	@echo "Gerando Scanner"
	@$(LEX) $(LFLAGS) -o$@ $<

#${OBJDIR}/bla.o: src/bla.cpp src/bla.h 
#	@echo "Compilando Modulo bla"
#	@${CXX} ${CXXFLAGS} -c $< -o $@

# =============
