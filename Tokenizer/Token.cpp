/*
 * Token.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#include "Token.h"

Token::Token(string type, string pattern, string lexeme){
	Token::type = type;
	Token::pattern = pattern;
	Token::lexeme = lexeme;
}

Token::~Token() {
	// TODO Auto-generated destructor stub
}


string Token::getType(void){
	return type;
}

string Token::getLexeme(void){
	return lexeme;

}
string Token::getPattern(void){
	return pattern;
}
