/* INCLUDE GUARD */
/****************************************/
#ifndef SYNTAX_ANALYZER_GENERATOR_H_
#define SYNTAX_ANALYZER_GENERATOR_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include "../rule_extractor/Production.h"
#include "../rule_extractor/Node.h"
#include "Derivation_Table.h"
#include "FirstFollow.h"
#include "../rule_extractor/GrammerParser.h"
#include <map>
#include <set>

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class Syntax_Analyzer_Generator{

public:
	/* CONSTRUCTOR AND DESTRUCTOR */
	Syntax_Analyzer_Generator() ;
	virtual ~Syntax_Analyzer_Generator() ;

public:
	/* INTERFACE METHODS */
	static Derivation_Table generate_derivation_table(vector<Production*> rules);

private:
	/* HELPER METHODS */
	static bool has_epsilon(set<Node>);
	static bool has_dollar(set<Node>);
};

#endif /* DERIVATION_TABLE_H_ */
