/*
 * GrammerParser.h
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#ifndef GRAMMERPARSER_H_
#define GRAMMERPARSER_H_

#include <vector>
#include <string>
#include "Production.h"

using namespace std;

class GrammerParser {
public:
	GrammerParser();
	virtual ~GrammerParser();

	// Example : x := 'a'B | C   will be {[name = x], [2 elements = {'a'B}, {C}]}
	// and 'a'B element will be two nodes {'a', terminal} and {B, non terminal}
	vector<Production>parse_grammer(string file_name);
};

#endif /* GRAMMERPARSER_H_ */
