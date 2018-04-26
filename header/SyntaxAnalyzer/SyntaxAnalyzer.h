/* INCLUDE GUARD */
/****************************************/
#ifndef SYNTAXANALYZER_H_
#define SYNTAXANALYZER_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include "../LexcialAnalyzer/Tokenizer/Token.h"
#include "ParserTable/DerivationTable.h"
#include "GrammerExtractor/ProductionElement.h"
#include "GrammerExtractor/Node.h"
#include <stack>

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class SyntaxAnalyzer {

public:
	/* CONSTRUCTOR*/
	SyntaxAnalyzer(void);
	virtual ~SyntaxAnalyzer(void);

public:
	/* INTERFACE METHODS */
	static void analyze_prog(vector<Token> user_prog , DerivationTable derivation_table);
	/* utility methods */
	static string stack_to_string(stack<Node*> stack);

};

#endif /* SYNTAXANALYZER_H_ */
