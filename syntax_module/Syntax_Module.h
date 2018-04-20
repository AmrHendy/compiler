/* INCLUDE GUARD */
/****************************************/
#ifndef SYNTAX_MODULE_H_
#define SYNTAX_MODULE_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include "derivation_table_generator/Derivation_Table.h"
#include "../lexical_module/Lexical_Analyzer/Token.h"
#include "syntax_analyzer/Syntax_Analyzer.h"
#include "derivation_table_generator/Syntax_Analyzer_Generator.h"
#include "rule_extractor/GrammerParser.h"
#include <vector>

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class Syntax_Module
{
private:
    /* CLASS ATTRIBUTES */
    vector<Production*> cfg_rules;
    vector<Token> prog_tokens;
    Syntax_Analyzer syntax_analyzer;
    Derivation_Table derivation_table;

public:
	/* CONSTRUCTOR AND DESTRUCTOR */
    Syntax_Module(string cfg_rules);
    virtual ~Syntax_Module(void);

public:
    /* INTERFACE METHODS */
    void generate_derivation_table(void);
    void select_prog(vector<Token> prog_tokens);
    void analyze_syntax(void); 


};

#endif /* SYNTAX_MODULE_H_ */
