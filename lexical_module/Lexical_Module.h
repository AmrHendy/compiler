/*
 * LexicalAnalyzer.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef LEXICAL_MODULE_H_
#define LEXICAL_MODULE_H_

#include <string>
#include "Lexical_Analyzer/Lexical_Analyzer.h"
#include "LexcialAnalyzerGenerator.h"

using namespace std;

class Lexical_Module
{
public:
	/**/
    Lexical_Module(string lexical_rules_directory);
    virtual ~Lexical_Module();
    /**/
    void generate_minimized_dfa_table(void);
    void select_prog(string user_prog_directory); /* selects user_prog to compile (tokenize) */
    Token next_token();
    vector<Token> get_all_tokens() ;

private:
	string lexical_rules_directory;
    Lexical_Analyzer lexical_analyzer;
    TransitionTable minimized_dfa_table;
};

#endif /* LEXICALANALYZER_H_ */
