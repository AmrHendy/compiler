/*
 * LexicalAnalyzer.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */


#include "Syntax_Module.h"

Syntax_Module::Syntax_Module(string cfg_rules)
{
//	Logger::print_string("Starting lexical analyzing \n ------------------ ") ;
    this->cfg_rules = cfg_rules;
}

Syntax_Module::~Syntax_Module()
{
    // TODO Auto-generated destructor stub
}

void
Syntax_Module::generate_derivation_table(void)
{
	derivation_table = Syntax_Analyzer_Generator::generate_derivation_table(cfg_rules);
}


void 
Syntax_Module::select_prog(vector<Token> prog_tokens){
	this->prog_tokens = prog_tokens;
}

void
Syntax_Module::analyze_syntax(void)
{
	syntax_analyzer.analyze_prog(prog_tokens, derivation_table);
}
