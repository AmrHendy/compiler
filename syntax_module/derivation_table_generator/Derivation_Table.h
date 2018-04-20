/* INCLUDE GUARD */
/****************************************/
#ifndef DERIVATION_TABLE_H_
#define DERIVATION_TABLE_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include "../rule_extractor/Node.h"
#include "../rule_extractor/ProductionElement.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class Derivation_Table{

private:
	/* CLASS ATTRIBUTES */
	map<pair<string,string>,ProductionElement*> Table ;

public:
	/* CONSTRUCTOR AND DESTRUCTOR */
	Derivation_Table(void);
	virtual ~Derivation_Table(void);

public:
	/* INTERFACE METHODS */
	bool add_transition (string non_terminal , string terminal , ProductionElement* rule) ;
	ProductionElement* get_transition (string non_terminal , string terminal) ;
	string get_non_terminal_start();
	void print(void) ;



};

#endif /* DERIVATION_TABLE_H_ */
