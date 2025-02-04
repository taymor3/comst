%{
#include <stdio.h>
#include <string.h>
void showError();
#include "part3_helpers.h"
#include "parser.tab.hpp"
%}

%option yylineno noyywrap


digit       ([0-9])
letter      ([a-zA-Z])
whitespace  ([\t ])
escaped	    ([tn"])
symbols     ([\(\)\{\},;:])

id		({letter}+(_|{digit}|{letter})*)
integernum	({digit}+)
realnum		({digit}+\.{digit}+)
str		(\"(?:\\{escaped}|[^\\\"\n\r])*\")
comment		(#[^\n\r]*)

%%
int|float|void|write|read|optional|while|do|if|then|else|return	{
	// In case of reserved word
	yylval = new Terminal(yytext);	
	// all possiblities of yytext
	if(!strcmp(yytext,"int"))
		return INT;
	else if(!strcmp(yytext,"float"))
		return FLOAT;
	else if(!strcmp(yytext,"void"))
		return VOID;
	else if(!strcmp(yytext,"write"))
		return WRITE;
	else if(!strcmp(yytext,"read"))
		return READ;
	else if(!strcmp(yytext,"optional"))
		return OPTIONAL;
	else if(!strcmp(yytext,"while"))
		return WHILE;
	else if(!strcmp(yytext,"do"))
		return DO;
	else if(!strcmp(yytext,"if"))
		return IF;
	else if(!strcmp(yytext,"then"))
		return THEN;
	else if(!strcmp(yytext,"else"))
		return ELSE;
	else if(!strcmp(yytext,"return"))
		return RETURN;
	else // just for code completeness, won't run
		return 0;
}

{id}	{
	yylval = new Terminal("id",yytext);	
	return ID;
}

{integernum}		{
	yylval = new Terminal("integernum",yytext);
	return INTEGERNUM;
}

{realnum}  {
	yylval = new Terminal("realnum",yytext);
	return	REALNUM;
}


{str}	   {
	// remove quotation marks from string
	yytext[strlen(yytext)-1] = 0;
	yylval = new Terminal("str",yytext+1);
	return	STR;
}


==|<>|<|<=|>|>=		{
	yylval = new Terminal("relop",yytext);
	return	RELOP;
}


\+|\-		{
	yylval = new Terminal("addop",yytext);
	return	ADDOP;
}


\*|\/		{
	yylval = new Terminal("mulop",yytext);
	return	MULOP;
}

=			{
	yylval = new Terminal("assign",yytext);
	return	ASSIGN;
}


&&			{
	yylval = new Terminal("and",yytext);
	return	AND;
}

\|\|		{
	yylval = new Terminal("or",yytext);
	return	OR;
}


!			{
	yylval = new Terminal("not",yytext);
	return	NOT;
}

{symbols}	{
	yylval = new Terminal(yytext);
	return	yytext[0];
}

[\n\r]							;
{whitespace}					;			
{comment}						;			
.								showError();                           
%%

void showError()
{
	printf("Lexical error: '%s' in line number %d\n", yytext, yylineno);
	exit(1);
}
