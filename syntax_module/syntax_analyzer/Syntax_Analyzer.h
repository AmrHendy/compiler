
#ifndef SYNTAX_ANALYZER_H_
#define SYNTAX_ANALYZER_H_

#include <vector>
#include "../../lexical_module/Lexical_Analyzer/Token.h"
#include "../derivation_table_generator/Derivation_Table.h"

using namespace std;

class Syntax_Analyzer {
public:
	Syntax_Analyzer();
	virtual ~Syntax_Analyzer();
	void analyze_prog(vector<Token> user_prog , Derivation_Table derivation_table);

};

#endif /* SYNTAX_ANALYZER_H_ */
