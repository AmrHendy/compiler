#include "Syntax_Analyzer_Generator.h"


Syntax_Analyzer_Generator::Syntax_Analyzer_Generator()
{

}

Syntax_Analyzer_Generator::~Syntax_Analyzer_Generator()
{

}


Derivation_Table
Syntax_Analyzer_Generator::generate_derivation_table(vector<Production*> rules)
{
	/* GENERATING FIRST & FOLLOW */
	map<string,set<Node>> first,follow ;
	First_Follow f_f = First_Follow(rules) ;
	first = f_f.get_first();
	follow = f_f.get_follow();

	/* GENERATE TABLE AFTER FIRST FOLLOW IS DONE */

}
