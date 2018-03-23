/*
 * compiler.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include <bits/stdc++.h>
#include "LexicalAnalyzer.h"

using namespace std;

int main() {
	LexicalAnalyzer lexicalAnalyzer = LexicalAnalyzer("rules.txt", "prog.txt");
	for(int i=0;i<10;i++){
		Token token = lexicalAnalyzer.next_token();
		//cout << "Lexeme ==> " << token.getLexeme() << " |||| " << "Type ==> " << token.getType();
	}
	return 0;
}
