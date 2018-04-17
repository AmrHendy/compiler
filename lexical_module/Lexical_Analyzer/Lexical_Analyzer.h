/*
 * Tokenizer.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef LEXICAL_ANALYZER_H_
#define LEXICAL_ANALYZER_H_

#include <string>
#include "../Rule_Extractor/FileHandler.h"
#include "../STRUCTURES/TransitionTable.h"
#include "../STRUCTURES/CompositeState.h"
#include "Token.h"

using namespace std;

class Lexical_Analyzer
{
public:
    Lexical_Analyzer(TransitionTable minimized_dfa_table,
              string          user_program_directory);

    Lexical_Analyzer();

    virtual ~Lexical_Analyzer();

    /* interface functions */
    Token next_token();

private:

    /* utility functions */
    Token get_correct_token(vector<Rule> conflicting_tokens,
                            string       lexeme);

    /* attributes */
    string user_program;

    /* pointers */
    int current_index = 0;

    /* current state pointer */
    TransitionTable minimized_dfa_table;
};
#endif /* TOKENIZER_H_ */


//~ Formatted by Jindent --- http://www.jindent.com
