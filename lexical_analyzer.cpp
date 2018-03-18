/* IMPORT LIBRARIES */
/*********************************************/
using namespace std;

/* MEMBER FUNCTION IMPLEMENTATION */
/*********************************************/
Lexical_Analyzer::Lexical_Analyzer(string language_rules_directory, string user_prog_directory)
{
   Lexical_Analyzer_Genertor lexical_analyzer_generator(language_rules_directory);
   Transition_Table minimized_dfa_table=lexical_analyzer_generator.generate_minimal_dfa();
   Tokenizer tokenizer(minimized_dfa_table, user_prog_directory);
   this.tokenizer=tokenizer;
}

Lexical_Analyzer::~Lexical_Analyzer(void)
{
   
}

/* INTERFACE FUNCTIONS */
/*********************************************/
Token
next_token()
{
	tokenizer.next_token();
}