/*
 * compiler.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "../header/LexcialAnalyzer/LexicalModule.h"
#include "../header/SyntaxAnalyzer/SyntaxModule.h"
#include "../header/Tester/Tester.h"

using namespace std;

int main()
{
    string lexical_rules_dir = "tests/lexical_rules.txt";
    string syntax_rules_dir = "tests/small_syntax_rules.txt";
    string user_prog_dir = "tests/small_user_prog.txt";
    string parser_table_dir = "tests/ParserTable.txt";

    /* generate compiler for specified language */
    LexicalModule lexical_module = LexicalModule(lexical_rules_dir);
    lexical_module.generate_lexical_analyzer();
    cout << "Finished Generating Lexical Analyzer\n";

    /* compile selected user prog */
	lexical_module.select_prog(user_prog_dir);
	vector<Token> prog_tokens = lexical_module.get_all_tokens();
	cout << "Finished Tokenizer\n";


    SyntaxModule syntax_module = SyntaxModule(syntax_rules_dir);
    Tester::testGrammerParser(syntax_rules_dir);
    cout << "Finished Parsing Grammer\n";

    syntax_module.generate_syntax_analyzer(parser_table_dir);
    Tester::testFirstFollow(syntax_rules_dir);
    cout << "Finished Building Parser Table\n";


    syntax_module.select_prog(prog_tokens);
    syntax_module.analyze_syntax();
    cout << "Finished Parsing the tokens\n";
    return 0;
}
