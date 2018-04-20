/*
 * Production.cpp
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#include "../../../header/SyntaxAnalyzer/GrammerExtractor/Production.h"

Production::Production(string LHSName) {
	LHSNode = LHSName;
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

void Production::add_element(ProductionElement *elem){
	RHS.push_back(elem);
}

void Production::add_element(vector<ProductionElement*> elems){
	for(ProductionElement* elem : elems){
		add_element(elem);
	}
}


string Production::get_LHS_name(){
	return LHSNode;
}

vector<ProductionElement*> Production::get_RHS_elements(){
	return RHS;
}
