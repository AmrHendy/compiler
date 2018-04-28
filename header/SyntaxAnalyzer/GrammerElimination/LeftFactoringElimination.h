
#ifndef HEADER_SYNTAXANALYZER_GRAMMERELIMINATION_LEFTFACTORINGELIMINATION_H_
#define HEADER_SYNTAXANALYZER_GRAMMERELIMINATION_LEFTFACTORINGELIMINATION_H_

#include <vector>
#include "../GrammerExtractor/Production.h"
#include <iostream>

using namespace std;

class LeftFactoringElimination {
public:
	LeftFactoringElimination(vector<Production*> rules);
	virtual ~LeftFactoringElimination();
	vector<Production*> get_left_factor_rules();

private:
	string start_non_terminal;
	vector <Production*> rules;
    vector<Production*> result_rules;

    string get_correct_name(string non_terimnal);
    void Left_Factoring_controller(vector<Production*> rules);
    vector <int> get_matched_indexes(string non_terminal,vector<ProductionElement*> RHS ,ProductionElement* element,ProductionElement* matched_element,int index);
    void apply_left_factor(string non_terminal,vector<ProductionElement*> RHS,vector<int> matched_indexes,ProductionElement* matched_element);
    void reorder();
};

#endif /* HEADER_SYNTAXANALYZER_GRAMMERELIMINATION_LEFTFACTORINGELIMINATION_H_ */
