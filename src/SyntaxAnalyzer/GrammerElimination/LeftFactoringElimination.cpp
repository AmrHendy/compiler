/*
 * LeftFactoringElimination.cpp
 * Created on: Apr 27, 2018
 * Author: Amr Hendy
 */

#include "../../../header/SyntaxAnalyzer/GrammerElimination/LeftFactoringElimination.h"

LeftFactoringElimination::LeftFactoringElimination(vector <Production*> rules) {
	start_non_terminal = rules[0]->get_LHS_name();
	this->rules=rules;
	this->Left_Factoring_controller (this->rules);
}

LeftFactoringElimination::~LeftFactoringElimination() {
	// TODO Auto-generated destructor stub
}

vector<Production*> LeftFactoringElimination::get_left_factor_rules(){
	return result_rules;
}

void LeftFactoringElimination::Left_Factoring_controller (vector <Production*> rules){
	string non_terminal;
	vector<ProductionElement*> RHS;
	vector<int> matched_indexes;
	result_rules=rules;
	for (int i=0;i<result_rules.size();i++){
		non_terminal=result_rules[i]->get_LHS_name();
		RHS=result_rules[i]->get_RHS_elements();
		ProductionElement* matched_element = new ProductionElement();
		for (int j=0;j<RHS.size();j++){
			matched_indexes = get_matched_indexes(non_terminal,RHS,RHS[j],matched_element,j);
			if (matched_indexes.size() > 1){
				apply_left_factor(non_terminal,RHS,matched_indexes,matched_element);
				result_rules.erase(result_rules.begin()+i);
				i--;
				break;
			}
		}
	}
	reorder();
}


vector <int> LeftFactoringElimination::get_matched_indexes(string non_terminal,vector<ProductionElement*> RHS ,ProductionElement* element,ProductionElement* matched_element,int index){
	bool is_matched;
	vector<int> matched_indexes;
	matched_indexes.push_back(index);
	vector<Node*> element_nodes = element->get_nodes();
	vector<Node*> matched_nodes;
	vector<Node*> RHS_nodes;
	for (int i=index+1;i<RHS.size();i++){
		is_matched=false;
		RHS_nodes=RHS[i]->get_nodes();
		// get the maximum matched element
		if (matched_nodes.empty()&&element_nodes[0]->get_name()==RHS_nodes[0]->get_name()){
			is_matched=true;
			for (int j=0;j<min(element_nodes.size(),RHS_nodes.size());j++){
				if (element_nodes[j]->get_name()==RHS_nodes[j]->get_name()){
					matched_nodes.push_back(new Node(element_nodes[j]->get_name(), element_nodes[j]->get_type()));
				}
				else{
					break;
				}
			}
		}
		else if (!matched_nodes.empty()&&element_nodes[0]->get_name()==RHS_nodes[0]->get_name()){
			is_matched=true;
			for (int j=0;j<matched_nodes.size()&&RHS_nodes.size()>=matched_nodes.size();j++){
				if(RHS_nodes[j]->get_name()!=matched_nodes[j]->get_name()){
					is_matched=false;
					break;
				}
			}
		}
		if (is_matched)
			matched_indexes.push_back(i);
	}

	for(Node* nodee : matched_nodes){
		matched_element->add_node(nodee);
	}
	return matched_indexes;
}


void LeftFactoringElimination::apply_left_factor(string non_terminal,vector<ProductionElement*> RHS,vector<int> matched_indexes,ProductionElement* matched_element){
	Production* rule1 = new Production(non_terminal);
	Production* rule2 = new Production(get_correct_name(non_terminal));
	Node* temp_node = new Node(rule2->get_LHS_name(), NonTerminal);
	ProductionElement* temp_element = new ProductionElement();
	bool exist,only_one_ebsilon;

	for(Node* nodee : matched_element->get_nodes()){
		temp_element->add_node(new Node(nodee->get_name(), nodee->get_type()));
	}
	temp_element->add_node(temp_node);
	rule1->add_element(temp_element);
	for (int i=0;i<RHS.size();i++){
		exist=false;
		for (int j=0;j<matched_indexes.size();j++){
			if (i==matched_indexes[j]){
				exist=true;
			}
		}
		if (exist){
			for (int j=0;j<matched_element->get_nodes().size();j++){
				RHS[i]->remove_first_node();
			}
			if (RHS[i]->get_nodes().empty() && !only_one_ebsilon){
				Node* epsilon = new Node("'\\L'",Terminal);
				RHS[i]->add_node(epsilon);
				rule2->add_element(RHS[i]);
				only_one_ebsilon = true;
			}
			else if(!RHS[i]->get_nodes().empty())
				rule2->add_element(RHS[i]);
		}
		else{
			rule1->add_element(RHS[i]);
		}
	}
	result_rules.push_back(rule1);
	result_rules.push_back(rule2);
}

string LeftFactoringElimination::get_correct_name(string non_terimnal){
	string result=non_terimnal,temp;
	bool derived;
	for (int i=0;i<result_rules.size();i++){
		derived=false;
		temp=result_rules[i]->get_LHS_name();
		if (result.size()<=temp.size()&&result==temp.substr(0,result.size())){
			derived=true;
			for(int j=result.size();j<temp.size();j++){
				if (temp[j]!='\''){
					derived=false;
					break;
				}
			}
		}
		if (derived)
			result=temp;
	}
	return result+"'";
}

void LeftFactoringElimination::reorder(){
	vector<Production*> ordered;
	for(Production* prod : result_rules){
		if(prod->get_LHS_name() == start_non_terminal){
			ordered.push_back(prod);
			break;
		}
	}

	for(Production* prod : result_rules){
		if(prod->get_LHS_name() != start_non_terminal){
			ordered.push_back(prod);
		}
	}
	result_rules = ordered;
}
