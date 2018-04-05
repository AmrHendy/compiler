/*
 * compiler.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include <bits/stdc++.h>
#include <ctime>
#include "LexcialAnalyzerGenerator.h"
#include "LexicalAnalyzer.h"

using namespace std;

int main()
{
	cout << "hello";
	LexicalAnalyzer lexicalAnalyzer = LexicalAnalyzer("rules.txt", "prog.txt");

    clock_t begin = clock() ;

    cout << "tokenizer start : \n" ;

    while(true)
    {
        Token token = lexicalAnalyzer.next_token();
        if(token.getType() == "INVALID")
        {
            break;
        }
        cout << "Lexeme ==> " << token.getLexeme() << " |||| " << "Type ==> " << token.getType() << endl;
    }

    clock_t end = clock() ;

    cout << "tokenizer took " << double(end-begin) / CLOCKS_PER_SEC<< " secs\n" ;

    return 0;
}
