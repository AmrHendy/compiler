#ifndef LEXICAL_ANALYZER_H_  /* Include guard */
#define LEXICAL_ANALYZER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Lexical_Analyzer
{
	public:
	/* attributes */
	Tokenizer tokenizer;

	/* constructor */
    Lexical_Analyzer_Generator(string language_rules_directory, string user_prog_directory);   // This is the constructor declaration
    ~Lexical_Analyzer_Generator(void);  // This is the destructor: declaration

    /* interface functions */
    Token next_token();
    
};


#endif // COMMANDS_H_