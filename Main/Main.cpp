/*
 * compiler.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include <bits/stdc++.h>
#include <ctime>
#include "LexcialAnalyzerGenerator.h"
#include "LexicalAnalyzer.h"
#include "../Tester.h"

using namespace std;

int main()
{
	/*

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

	*/

    // to test parser utilities
    Tester::test("CFG.txt");
    return 0;
}
