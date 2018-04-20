/* INCLUDE GUARD */
/****************************************/
#ifndef DERIVATIONTABLE_H_
#define DERIVATIONTABLE_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include "../GrammerExtractor/Node.h"
#include "../GrammerExtractor/ProductionElement.h"
#include "../../FileHandler/FileWriter.h"
#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class DerivationTable{

private:
	/* CLASS ATTRIBUTES */
	map<pair<string,string>,ProductionElement*> Table ;
	set<string> terminals, non_terminals;

public:
	/* CONSTRUCTOR AND DESTRUCTOR */
	DerivationTable(void);
	virtual ~DerivationTable(void);

public:
	/* INTERFACE METHODS */
	bool add_transition (string non_terminal , string terminal , ProductionElement* rule) ;
	ProductionElement* get_transition (string non_terminal , string terminal) ;
	string get_non_terminal_start();
	void print(string file_name) ;
	void set_terminals(set<string> terminal_names);
	void set_non_terminals(set<string> terminal_names);
};

#endif /* DERIVATIONTABLE_H_ */
