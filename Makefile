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
	   ${OBJDIR}/driver.o ${OBJDIR}/addition.o ${OBJDIR}/number.o \
	   ${OBJDIR}/contexto.o

ARCHIVE_FILES = src/ bin/ Makefile README
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

clean:
	@rm -fr ${OBJDIR}/*
	@rm -fr ${BINNAME}
	@rm -fr src/scanner.cpp src/parser.h src/parser.cpp
	@rm -rf src/*.hh

run: all
	@echo "Executando: "
	@echo "======================"
	@./${BINNAME} ${PARAM}
	@echo "======================"

# =============

${BINNAME}: ${OBJS}
	@echo "Gerando ${BINNAME}!!"
	@${CXX} ${CXXFLAGS} ${OBJS} -o ${BINNAME}
	
${OBJDIR}/main.o: src/main.cpp
	@echo "Compilando Modulo Principal"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/contexto.o: src/contexto.cpp src/contexto.h
	@echo "Compilando Modulo Contexto"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/addition.o: src/addition.cpp src/addition.h
	@echo "Compilando Modulo Addition"
	@${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}/number.o: src/number.cpp src/number.h
	@echo "Compilando Modulo Number"
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
	@$(LEX) $(LFLAGS) -o $@ $<

#${OBJDIR}/bla.o: src/bla.cpp src/bla.h 
#	@echo "Compilando Modulo bla"
#	@${CXX} ${CXXFLAGS} -c $< -o $@

# =============
