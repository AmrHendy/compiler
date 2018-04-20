/*
 * LexicalAnalyzer.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef LEXICALMODULE_H_
#define LEXICALMODULE_H_

#include <string>
#include "Tokenizer/Tokenizer.h"
#include "LexcialAnalyzerGenerator.h"

using namespace std;

class LexicalModule
{
public:
	/**/
    LexicalModule(string lexical_rules_directory);
    virtual ~LexicalModule();
    /**/
    void generate_lexical_analyzer(void);
    void select_prog(string user_prog_directory); /* selects user_prog to compile (tokenize) */
    Token next_token();
    vector<Token> get_all_tokens() ;

private:
	string lexical_rules_directory;
	Tokenizer lexical_analyzer;
    TransitionTable minimized_dfa_table;
};

#endif /* LEXICALMODULE_H_ */
