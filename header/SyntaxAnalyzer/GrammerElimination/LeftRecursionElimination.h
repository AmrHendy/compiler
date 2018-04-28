#ifndef HEADER_SYNTAXANALYZER_GRAMMERELIMINATION_LEFTRECURSIONELIMINATION_H_
#define HEADER_SYNTAXANALYZER_GRAMMERELIMINATION_LEFTRECURSIONELIMINATION_H_


#include <vector>
#include <iostream>
#include <map>
#include "../GrammerExtractor/Production.h"

using namespace std;

class LeftRecursionElimination {

public:
	LeftRecursionElimination(vector <Production*> rules);
	virtual ~LeftRecursionElimination();

	vector<Production*> get_eliminated_rules();

private:
	string start_non_terminal;
	vector <Production*> rules;
	vector <Production*> result_rules;
    // manage the flow of code
	void Elimination_controller (vector <Production*> rules);    // get indexes of elements which have left recursion
	vector <int> get_matched_indexes(string non_terminal,vector<ProductionElement*>& RHS);
	vector<ProductionElement*> modify_RHS(vector<ProductionElement*>RHS,ProductionElement* temp,int index);
	int check_LR(string non_terminal);

	// eliminate left recursion and produce new rules with out left recursion;
	vector<Production*> elimination(string non_terminal,vector<ProductionElement*> elements,vector<int> matched_indexes);

	// get the next correct non terminal node.
	string get_correct_name(string non_terimnal);

	void reorder();
};

#endif /* HEADER_SYNTAXANALYZER_GRAMMERELIMINATION_LEFTRECURSIONELIMINATION_H_ */
