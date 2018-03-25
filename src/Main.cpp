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
	FileHandler::openNewTokenFile();
	while(true){
		Token token = lexicalAnalyzer.next_token();
		if(token.getType() == "INVALID")break;
		FileHandler::append(token.getLexeme(), token.getType());
	}
	return 0;
}
