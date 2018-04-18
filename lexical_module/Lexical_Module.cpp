/*
 * LexicalAnalyzer.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */


#include "Lexical_Module.h"
#include <iostream>

Lexical_Module::Lexical_Module(string lexical_rules_directory)
{
//	Logger::print_string("Starting lexical analyzing \n ------------------ ") ;
    this->lexical_rules_directory = lexical_rules_directory;
}

Lexical_Module::~Lexical_Module()
{
    // TODO Auto-generated destructor stub
}

void
Lexical_Module::generate_minimized_dfa_table(void)
{
    minimized_dfa_table = LexcialAnalyzerGenerator::generate_minimal_dfa(lexical_rules_directory);
}

void 
Lexical_Module::select_prog(string user_prog_directory){
    lexical_analyzer = Lexical_Analyzer(minimized_dfa_table, user_prog_directory);
}

Token Lexical_Module::next_token()
{
    //return Token("aa", "bb" , "cc");
    return lexical_analyzer.next_token();
}

 vector<Token> Lexical_Module::get_all_tokens() {
 	vector<Token> prog_tokens ;

 	while(true)
    {
        Token token = next_token();
        if(token.getType() == "INVALID")
        {
            break;
        }
        cout << "Lexeme ==> " << token.getLexeme() << " |||| " << "Type ==> " << token.getType() << endl;
        prog_tokens.push_back(token);
    }

    return prog_tokens ;

 }

 int main(){
	 Lexical_Module lex = Lexical_Module("lexical_rules.txt");
	 lex.generate_minimized_dfa_table();
	 lex.select_prog("user_prog.txt");
	 vector<Token> tokens = lex.get_all_tokens();
 }
