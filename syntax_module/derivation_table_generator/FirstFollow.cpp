/*
 * FirstFollow.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: abdelrhman
 */

#include <iostream>
#include "FirstFollow.h"
#include "../rule_extractor/GrammerParser.h"

First_Follow::First_Follow(vector<Production*> rules) {
	// TODO Auto-generated constructor stub
	this->rules = rules ;

	/*  GENERATE INDEX FOR RULES TO ACESS PRODUCTION WITH RHS NAME */
	generate_rules_index();

	/* GENERATE FIRST */
	for(Production* prod : rules){
		for(ProductionElement* elem : prod->get_RHS_elements())
			for(Node* node : elem->get_nodes())
				if(node->get_type() == Terminal || node->is_epsilon() )
					first_set[node->get_name()].insert(*node) ;
		first_set[prod->get_LHS_name()] = first(prod) ;
	}
}

First_Follow::~First_Follow() {
	// TODO Auto-generated destructor stub
}

map<string,set<Node>>
First_Follow::get_first() {
	return this->first_set ;
}

map<string,set<Node>>
First_Follow::get_follow() {
	return this->follow_set ;
}

void
First_Follow::generate_rules_index(){
	for(Production* p : rules){
		rules_index[p->get_LHS_name()] = p ;
	}
}


set<Node>
First_Follow::first(Node* node){
	set<Node> ret ;

	/* MEMORIZING NODE */
	if(first_set.find(node->get_name()) != first_set.end())
		return first_set[node->get_name()] ;

	if(node->get_type() == Terminal)
		ret.insert(*node) ;
	else if(rules_index.find(node->get_name()) != rules_index.end())
		ret = first(rules_index[node->get_name()]) ;

	/* MEMORIZING NODE */
	return first_set[node->get_name()] = ret ;
}

set<Node>
First_Follow::first(Production* prod){
	set<Node> ret ;
	for(ProductionElement* elem : prod->get_RHS_elements()){
		set<Node> res = first(elem) ;
		for(Node n : res )ret.insert(n) ;
	}
	return ret ;
}

set<Node>
First_Follow::first(ProductionElement* prod_elem){
	set<Node> ret ;
	for(Node* node : prod_elem->get_nodes()){
		set<Node> res = first(node) ;
		for(Node n : res )ret.insert(n) ;
		/* FOUND FIRST IN PRODUCTION ELEM elem Stop*/
		Node tmp = (*ret.begin()) ;
		if((int)ret.size() > 1 || ((int)ret.size() == 1 && ! tmp.is_epsilon() ) )
			break ;
	}
	return ret ;
}

int main(){
	GrammerParser gp = GrammerParser() ;
	vector<Production*> rules = gp.parse_grammer("CFG.txt");
	First_Follow f_f = First_Follow(rules) ;
	map<string,set<Node>> first = f_f.get_first() ;
	for(pair<string,set<Node>> p : first){
		cout << p.first << " : { " ;
		int k = 0 ;
		for(Node n : p.second){
			cout << n.get_name() ;
			if(k < (int)p.second.size()-1 )
				cout << " , " ;
			k++ ;
		}
		cout << " }\n" ;
	}
}




