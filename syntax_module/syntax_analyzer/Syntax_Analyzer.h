/* INCLUDE GUARD */
/****************************************/
#ifndef SYNTAX_ANALYZER_H_
#define SYNTAX_ANALYZER_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include <list>
#include "../../lexical_module/Lexical_Analyzer/Token.h"
#include "../derivation_table_generator/Derivation_Table.h"
#include "../rule_extractor/ProductionElement.h"
#include "../rule_extractor/Node.h"

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class Syntax_Analyzer {

public:
	/* CONSTRUCTOR*/
	Syntax_Analyzer(void);
	virtual ~Syntax_Analyzer(void);

public:
	/* INTERFACE METHODS */
	void analyze_prog(vector<Token> user_prog , Derivation_Table derivation_table);

};

#endif /* SYNTAX_ANALYZER_H_ */
