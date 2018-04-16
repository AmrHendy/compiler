/*
 * LexicalAnalyzer.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef SYNTAX_MODULE_H_
#define SYNTAX_MODULE_H_

#include "derivation_table_generator/Derivation_Table.h"
#include "../lexical_module/Lexical_Analyzer/Token.h"
#include "syntax_analyzer/Syntax_Analyzer.h"
#include "derivation_table_generator/Syntax_Analyzer_Generator.h"
#include <vector>

using namespace std;

class Syntax_Module
{
public:
	/**/
    Syntax_Module(string cfg_rules);
    virtual ~Syntax_Module();
    /**/
    void generate_derivation_table(void);
    void select_prog(vector<Token> prog_tokens);
    void analyze_syntax(); 

private:
    vector<Production> cfg_rules;
    vector<Token> prog_tokens;
    Syntax_Analyzer syntax_analyzer;
    Derivation_Table derivation_table;
};

#endif /* SYNTAX_MODULE_H_ */
