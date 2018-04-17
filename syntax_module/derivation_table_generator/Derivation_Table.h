#ifndef DERIVATION_TABLE_H_
#define DERIVATION_TABLE_H_

#include <map>
#include "../rule_extractor/Node.h"
#include "../rule_extractor/ProductionElement.h"

using namespace std;

class Derivation_Table{

public:
	Derivation_Table();
	virtual ~Derivation_Table();

public:
	bool add_transition (string non_terminal , string terminal , ProductionElement* rule) ;
	ProductionElement* get_transition (string non_terminal , string terminal) ;
	void print() ;

private:
	map<pair<string,string>,ProductionElement*> Table ;

};

#endif /* DERIVATION_TABLE_H_ */
