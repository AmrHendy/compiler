
#ifndef SYNTAX_ANALYZER_GENERATOR_H_
#define SYNTAX_ANALYZER_GENERATOR_H_


#include "../rule_extractor/Production.h"
#include "Derivation_Table.h"

using namespace std;

class Syntax_Analyzer_Generator{

public:
	Syntax_Analyzer_Generator() ;
	virtual ~Syntax_Analyzer_Generator() ;
	static Derivation_Table generate_derivation_table(vector<Production*> rules);

};

#endif /* DERIVATION_TABLE_H_ */
