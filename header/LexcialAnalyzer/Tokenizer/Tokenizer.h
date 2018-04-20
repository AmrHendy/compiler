/*
 * Tokenizer.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <string>
#include "../../FileHandler/FileReader.h"
#include "../../FileHandler/FileWriter.h"
#include "../MachineStructure/TransitionTable.h"
#include "../MachineStructure/CompositeState.h"
#include "Token.h"

using namespace std;

class Tokenizer {
public:
    Tokenizer(TransitionTable minimized_dfa_table, string user_program_directory);
    Tokenizer();
    virtual ~Tokenizer();

    /* interface functions */
    Token next_token();

private:
    /* utility functions */
    Token get_correct_token(vector<Rule> conflicting_tokens, string lexeme);


	/* attributes */
	string user_program;
	/* pointers */
	int current_index = 0;
	/* current state pointer */
	TransitionTable minimized_dfa_table;
};

#endif /* TOKENIZER_H_ */
