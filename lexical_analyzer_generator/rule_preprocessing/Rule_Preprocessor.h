#ifndef RULE_PREPROCESSOR_H_  /* Include guard */
#define RULE_PREPROCESSOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <vector>
#include <string>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Rule_Preprocessor
{
	private:
	/* attributes */
	string language_rules_directory;

	public:
	/* constructor */
    Rule_Preprocessor(string language_rules_directory);   // This is the constructor declaration
    ~Rule_Preprocessor(void);  // This is the destructor: declaration

    /* interface functions */
    vector<Rule> getRules();
 
};


#endif // COMMANDS_H_