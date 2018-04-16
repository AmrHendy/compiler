/*
 * GrammerParser.cpp
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#include "GrammerParser.h"

using namespace std;

GrammerParser::GrammerParser() {
	// TODO Auto-generated constructor stub
}

GrammerParser::~GrammerParser() {
	// TODO Auto-generated destructor stub
}

vector<Production*> GrammerParser::parse_grammer(string grammer_file_name){

	vector<string> lines = FileHandler::readLanguageRules(grammer_file_name);

	// construct the rules on multiple lines
	vector<string> rules;
	string curr_rule = "";
	for(string str_line : lines){
		if(str_line.find("::=") == string::npos || curr_rule.empty()){
			curr_rule += str_line;
		}
		else{
			rules.push_back(curr_rule);
			curr_rule = str_line;
		}
	}

	if(!curr_rule.empty()){
		rules.push_back(curr_rule);
	}

	vector<Production*> productions;

	// split the string into Elements then split the Element into Nodes.
	// now we have the production of the format we want.

	for(string rule_str : rules){
		// create static instance to be able to call the non static parse_rule function.
		GrammerParser static_instance;
		productions.push_back(static_instance.parse_rule(rule_str));
	}

	// we can merge the repeated productions into one production.
	// Example:
	// A ::= B
	// A ::= C
	// we can merge them into one A ::= B | C
	map<string, Production*> unique_productions;
	for(Production* production : productions){
		if(unique_productions.find(production->get_LHS_name()) != unique_productions.end()){
			unique_productions[production->get_LHS_name()]->add_element(production->get_RHS_elements());
		}
		else{
			unique_productions[production->get_LHS_name()] = production;
		}
	}

	vector<Production*> unique;
	map<string, Production*>::iterator it;
	for(it = unique_productions.begin(); it != unique_productions.end(); it++){
		unique.push_back(it->second);
	}
	return unique;
}

Production* GrammerParser::parse_rule(string rule_str){
	int equalIndex = rule_str.find("::=");
	//remove spaces from the result string
	string LHS = removeSpaces(rule_str.substr(0, equalIndex));
	Production* production = new Production(LHS);
	set<char> delim = {'|'};
	vector<string> elements = split(rule_str.substr(equalIndex + 3), delim);
	delim = {' '};
	for(string element : elements){
		ProductionElement* production_elem = new ProductionElement();
		vector<string> nodes = split(element, delim);
		for(string node_str : nodes){
			Node* node;
			node_str = removeSpaces(node_str);
			if(node_str.find("'") != string::npos){
				node = new Node(node_str, NodeType::Terminal);
			}
			else{
				node = new Node(node_str, NodeType::NonTerminal);
			}
			production_elem->add_node(node);
		}
		production->add_element(production_elem);
	}
	return production;
}


string GrammerParser::removeSpaces(string str) {
    string trimmedStr = "";
    for(int index = 0; index < str.length(); index++) {
        if(str[index] != ' ') {
            trimmedStr += str[index];
        }
    }
    return trimmedStr;
}

// split the string str to vector of strings according to |
vector<string> GrammerParser::split(string str, set<char> delim) {
    vector<string> splittedStr;
    set<char> delmiters = delim;
    string currentStr = "";
    for(int index = 0; index < (int)str.length(); index++) {
    	// take care of special case \| not split
        if(delmiters.count(str[index]) != 0 && index > 0 && str[index - 1] != '\\') {
            if(!currentStr.empty()) {
                splittedStr.push_back(currentStr);
            }
            currentStr = "";
        }
        else {
            currentStr += str[index];
        }
    }
    if(!removeSpaces(currentStr).empty()) {
        splittedStr.push_back(currentStr);
    }

    return splittedStr;
}
