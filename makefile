#makefile to create executable compiler

CC = g++ -std=c++11 -o 
LEX = flex
YACC = bison

all:	part3

parser.tab.cpp: parser.ypp part3_helpers.cpp part3_helpers.h
	$(YACC) -vd parser.ypp

lex.yy.c:	lexer.lex part3_helpers.cpp part3_helpers.h
	$(LEX) lexer.lex

part3:	lex.yy.c parser.tab.cpp part3_helpers.cpp part3_helpers.h
	$(CC) rx-cc parser.tab.cpp lex.yy.c part3_helpers.cpp 

clean:
	rm -f *.o parser.tab.cpp lex.yy.c parser.tab.hpp parser.output
