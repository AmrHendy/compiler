/*
 * LexicalModule.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */


#include "../../header/LexcialAnalyzer/LexicalModule.h"
#include <iostream>

LexicalModule::LexicalModule(string lexical_rules_directory)
{
    this->lexical_rules_directory = lexical_rules_directory;
}

LexicalModule::~LexicalModule()
{
    // TODO Auto-generated destructor stub
}

void
LexicalModule::generate_lexical_analyzer(void)
{
    minimized_dfa_table = LexcialAnalyzerGenerator::generate_minimal_dfa(lexical_rules_directory);
}

void 
LexicalModule::select_prog(string user_prog_directory){
    lexical_analyzer = Tokenizer(minimized_dfa_table, user_prog_directory);
}

Token LexicalModule::next_token()
{
    return lexical_analyzer.next_token();
}

vector<Token> LexicalModule::get_all_tokens() {
	FileWriter::openNewFile("output_tokens.txt");
	vector<Token> prog_tokens ;
 	while(true)
    {
        Token token = next_token();
        if(token.getType() == "INVALID")
        {
            break;
        }
        prog_tokens.push_back(token);
        string token_str = token.getLexeme() + "\t" + token.getType();
		FileWriter::append("output_tokens.txt", token_str);
    }
    return prog_tokens ;
}
