/* INCLUDE GUARD */
/****************************************/
#ifndef DERIVATIONTABLE_H_
#define DERIVATIONTABLE_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include "../GrammerExtractor/Node.h"
#include "../GrammerExtractor/ProductionElement.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class DerivationTable{

private:
	/* CLASS ATTRIBUTES */
	map<pair<string,string>,ProductionElement*> Table ;

public:
	/* CONSTRUCTOR AND DESTRUCTOR */
	DerivationTable(void);
	virtual ~DerivationTable(void);

public:
	/* INTERFACE METHODS */
	bool add_transition (string non_terminal , string terminal , ProductionElement* rule) ;
	ProductionElement* get_transition (string non_terminal , string terminal) ;
	string get_non_terminal_start();
	void print(void) ;
};

#endif /* DERIVATIONTABLE_H_ */
