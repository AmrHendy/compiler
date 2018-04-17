/*
 * ProductionElement.cpp
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#include "ProductionElement.h"
#include <iostream>

ProductionElement::ProductionElement() {
	// TODO Auto-generated constructor stub

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

void
ProductionElement::print(){
	for(Node* n : nodes){
		cout << n->get_name() ;
	}
}
