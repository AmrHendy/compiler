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
	while(true){
		Token token = lexicalAnalyzer.next_token();
		if(token.getType() == "INVALID")break;
		cout << "Lexeme ==> " << token.getLexeme() << " |||| " << "Type ==> " << token.getType() << endl;
	}
	return 0;
}
