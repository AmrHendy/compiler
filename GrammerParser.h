/*
 * GrammerParser.h
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#ifndef GRAMMERPARSER_H_
#define GRAMMERPARSER_H_

#include <vector>
#include <string>
#include <set>
#include <map>
#include "Production.h"
#include "Rule_Extractor/FileHandler.h"

using namespace std;

class GrammerParser {
public:
	GrammerParser();
	virtual ~GrammerParser();

	// Example : x := 'a'B | C   will be {[name = x], [2 elements = {'a'B}, {C}]}
	// and 'a'B element will be two nodes {'a', terminal} and {B, non terminal}
	static vector<Production*> parse_grammer(string file_name);

private:
	Production* parse_rule(string rule_str);
	string removeSpaces(string str);
	vector<string> split(string str, set<char> delim);
};

#endif /* GRAMMERPARSER_H_ */
