/*
 * ProductionElement.cpp
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#include "../../../header/SyntaxAnalyzer/GrammerExtractor/ProductionElement.h"
#include <iostream>


ProductionElement::ProductionElement() {
	// TODO Auto-generated constructor stub
	name = "";
}


ProductionElement::ProductionElement(string name = "") {
	// TODO Auto-generated constructor stub
	ProductionElement::name = name;
}

ProductionElement::~ProductionElement() {
	// TODO Auto-generated destructor stub
}

void ProductionElement::add_node(Node* node){
	nodes.push_back(node);
}

vector<Node*> ProductionElement::get_nodes(){
	return nodes;
}

void ProductionElement::print(){
	for(Node* n : nodes){
		cout << n->get_name();
	}
}

bool ProductionElement::is_synchronize(){
	return name == "SYNC";
}

bool ProductionElement::is_empty(){
	return name == "Error";
}

string ProductionElement::get_format(){
	string str = "";
	for(Node* n : nodes){
		string curr_name = n->get_name();
		if(curr_name == "'\\L'"){
			curr_name = "EPSILON";
		}
		str += curr_name + " ";
	}
	return str.substr(0, str.size() - 1);
}

string ProductionElement::get_name(){
	return name;
}
