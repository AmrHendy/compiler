
#ifndef SYNTAX_ANALYZER_GENERATOR_H_
#define SYNTAX_ANALYZER_GENERATOR_H_


#include "../rule_extractor/Production.h"
#include "../rule_extractor/Node.h"
#include "Derivation_Table.h"
#include "FirstFollow.h"
#include <map>
#include <set>

using namespace std;

class Syntax_Analyzer_Generator{

public:
	Syntax_Analyzer_Generator() ;
	virtual ~Syntax_Analyzer_Generator() ;
	static Derivation_Table generate_derivation_table(vector<Production*> rules);

private:
	static bool has_epsilon(set<Node>);
	static bool has_dollar(set<Node>);
};

#endif /* DERIVATION_TABLE_H_ */
