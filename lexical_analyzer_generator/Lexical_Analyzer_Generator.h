#ifndef LEXICAL_ANALYZER_GENERATOR_H_  /* Include guard */
#define LEXICAL_ANALYZER_GENERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <vector>
#include <string>
#include <fstream>
#include "lexical_analyzer_generator/data_structures/transition_table/Transition_Table.h"
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Lexical_Analyzer_Generator
{
public:
    /* attributes */
    string language_rules_directory;

    /* constructor */
    Lexical_Analyzer_Generator(string language_rules_directory);   // This is the constructor declaration
    ~Lexical_Analyzer_Generator(void);  // This is the destructor: declaration

    /* interface functions */
    Transition_Table generate_minimal_dfa(void);

};


#endif // COMMANDS_H_
