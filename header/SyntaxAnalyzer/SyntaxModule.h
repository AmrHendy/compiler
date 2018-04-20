/* INCLUDE GUARD */
/****************************************/
#ifndef SYNTAXMODULE_H_
#define SYNTAXMODULE_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include "ParserTable/DerivationTable.h"
#include "../LexcialAnalyzer/Tokenizer/Token.h"
#include "SyntaxAnalyzerGenerator.h"
#include "GrammerExtractor/GrammerParser.h"
#include "SyntaxAnalyzer.h"
#include <vector>

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class SyntaxModule
{
private:
    /* CLASS ATTRIBUTES */
    vector<Production*> cfg_rules;
    vector<Token> prog_tokens;
    DerivationTable derivation_table;

public:
	/* CONSTRUCTOR AND DESTRUCTOR */
    SyntaxModule(string cfg_rules);
    virtual ~SyntaxModule(void);

public:
    /* INTERFACE METHODS */
    void generate_syntax_analyzer(string output_table_file);
    void select_prog(vector<Token> prog_tokens);
    void analyze_syntax(void); 
};

#endif /* SYNTAXMODULE_H_ */
