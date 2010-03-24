# Makefile para TP4
# by Leonardo Vilela Teixeira <vilela@dcc.ufmg.br>

CXX = g++
OBJDIR = bin/obj
BINNAME = bin/tiny
CXXFLAGS = -Wall -g 
OBJS = ${OBJDIR}/main.o 

ARCHIVE_FILES = src/ bin/ Makefile
ARCHIVE_NAME = tiny.tar.gz

# =============

.PHONY: clean archive run all 

# =============

all: ${BINNAME}

archive: all
	@rm -rf ${ARCHIVE_NAME}
	@echo "Compactando TP"
	@tar -czf ${ARCHIVE_NAME} ${ARCHIVE_FILES}
	@rm -rf archive

# =============

${BINNAME}: ${OBJS}
	@echo "Gerando ${BINNAME}!!"
	@${CXX} ${CXXFLAGS} ${OBJS} -o ${BINNAME}
	
${OBJDIR}/main.o: src/main.cpp
	@echo "Compilando Modulo Principal"
	@${CXX} ${CXXFLAGS} -c $< -o $@

#${OBJDIR}/analise.o: src/analise.c src/analise.h
#	@echo "Compilando Modulo Analise"
#	@${CXX} ${CXXFLAGS} -c $< -o $@


# =============

clean:
	@rm -fr ${OBJDIR}/*
	@rm -fr ${BINNAME}

run: all
	@echo "Executando: "
	@echo "======================"
	@./${BINNAME} -i "bin/in.txt" -o bin/out.txt -m -t
	@echo "======================"
