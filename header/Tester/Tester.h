/*
 * Tester.h
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#ifndef TESTER_H_
#define TESTER_H_



#include <string>
#include <sstream>
#include <iostream>
#include "../SyntaxAnalyzer/GrammerExtractor/GrammerParser.h"
#include "../SyntaxAnalyzer/ParserTable/FirstFollow.h"
#include "../FileHandler/FileWriter.h"
#include "../SyntaxAnalyzer/SyntaxAnalyzerGenerator.h"
#include "../SyntaxAnalyzer/GrammerElimination/LeftFactoringElimination.h"
#include "../SyntaxAnalyzer/GrammerElimination/LeftRecursionElimination.h"

using namespace std;

class Tester {
public:
	Tester();
	virtual ~Tester();

	static void testGrammerParser(string file_name);
	static void testFirstFollow(string file_name);
	static void testElimination();
	static void printGrammerFile(string file_name, vector<Production*> rules);
};

#endif /* TESTER_H_ */
