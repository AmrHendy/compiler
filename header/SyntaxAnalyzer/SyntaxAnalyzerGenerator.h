/* INCLUDE GUARD */
/****************************************/
#ifndef SYNTAXANALYZERGENERATOR_H_
#define SYNTAXANALYZERGENERATOR_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include "GrammerExtractor/Production.h"
#include "GrammerExtractor/Node.h"
#include "GrammerExtractor/GrammerParser.h"
#include "ParserTable/DerivationTable.h"
#include "ParserTable/FirstFollow.h"
#include <map>
#include <set>

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class SyntaxAnalyzerGenerator{

public:
	/* CONSTRUCTOR AND DESTRUCTOR */
	SyntaxAnalyzerGenerator() ;
	virtual ~SyntaxAnalyzerGenerator() ;

public:
	/* INTERFACE METHODS */
	static DerivationTable generate_derivation_table(vector<Production*> rules, string output_table_file);

private:
	/* HELPER METHODS */
	static bool has_epsilon(set<Node>);
	static bool has_dollar(set<Node>);
};

#endif /* DERIVATION_TABLE_H_ */
