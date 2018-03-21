#ifndef LEXICAL_ANALYZER_H_  /* Include guard */
#define LEXICAL_ANALYZER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <vector>
#include <string>
#include <fstream>
#include "lexical_tokenizer/Tokenizer.h"

using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Lexical_Analyzer
{
public:
    /* attributes */
    Tokenizer tokenizer;

    /* constructor */
    Lexical_Analyzer(string language_rules_directory, string user_prog_directory);   // This is the constructor declaration
    ~Lexical_Analyzer(void);  // This is the destructor: declaration

    /* interface functions */
    Token next_token();

};


#endif // COMMANDS_H_
