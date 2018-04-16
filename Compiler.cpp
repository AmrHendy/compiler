
#include "lexical_module/Lexical_Module.h"
#include "syntax_module/Syntax_Module.h"

using namespace std;

int main()
{

    string lexical_rules_dir = "lexical_rules.txt";
    string syntax_rules_dir = "syntax_rules.txt";
    string user_prog_dir = "user_prog.txt";

    /* generate compiler for specified language */
    Lexical_Module lexical_module = Lexical_Module(lexical_rules_dir);
    lexical_module.generate_minimized_dfa_table();

    Syntax_Module syntax_module = Syntax_Module(syntax_rules_dir);
    syntax_module.generate_derivation_table();

    /* compile selected user prog */
    lexical_module.select_prog(user_prog_dir);
    vector<Token> prog_tokens = lexical_module.get_all_tokens();
    syntax_module.select_prog(prog_tokens);
    syntax_module.analyze_syntax();

    
    return 0;
}


/*

    TO DO
    ERROR HANDLING
    01_ what will happen when tokenizer sends invalid tokens
    02_ invalid syntax/parse trees

*/
