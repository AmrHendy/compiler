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
#include "../FileHandler/FileWriter.h"

using namespace std;

class Tester {
public:
	Tester();
	virtual ~Tester();

	static void test(string file_name);
};

#endif /* TESTER_H_ */
