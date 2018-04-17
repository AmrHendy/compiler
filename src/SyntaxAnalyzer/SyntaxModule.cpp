/* INCLUDE HEADER */
/****************************************/
#include "../../header/SyntaxAnalyzer/SyntaxModule.h"

/* IMPLEMENT CONSTRUCTOR */
/****************************************/
SyntaxModule::SyntaxModule(string cfg_rules)
{
	SyntaxModule::cfg_rules = GrammerParser::parse_grammer(cfg_rules) ;
}

SyntaxModule::~SyntaxModule()
{
    // TODO Auto-generated destructor stub
}

/* IMPLEMENT INTERFACE METHODS */
/****************************************/
void
SyntaxModule::generate_syntax_analyzer()
{
	derivation_table = SyntaxAnalyzerGenerator::generate_derivation_table(cfg_rules);
}

void 
SyntaxModule::select_prog(vector<Token> prog_tokens){
	this->prog_tokens = prog_tokens;
}

void
SyntaxModule::analyze_syntax(void)
{
	SyntaxAnalyzer::analyze_prog(prog_tokens, derivation_table);
}
