%{
#include<stdio.h>
%}
%%
"if" {printf("Lexeme = if , Type = T_if");}
"else" {printf("Lexeme = else , Type = T_else");}
"while" {printf("Lexeme = while , Type = T_while");}
"boolean" {printf("Lexeme = boolean , Type = T_boolean");}
"int" {printf("Lexeme = int , Type = T_int");}
"float" {printf("Lexeme = flloat , Type = T_float");}

[a-z|A-Z][a-z|A-Z|0-9]* {printf("Identifier");}
[0-9]+|[0-9]+"."[0-9]+(E[0-9]+)?  {printf("number");}

==|!=|>|<=|>=|<  {printf("relop");}
"+"|- {printf("addop");}
"*"|"/" {printf("mulop");}
"=" {printf("assign");}

";" {printf(";");}
"," {printf(",");}
"(" {printf("(");}
")" {printf(")");}
"}" {printf("}");}
"{" {printf("{");}

%%
int yywrap()
{
   return 1;
}
main()
{
   printf("Enter the code you want to analyze\n");
   yylex();
}

