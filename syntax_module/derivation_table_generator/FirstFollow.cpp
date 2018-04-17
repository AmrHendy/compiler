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

	/*  GENERATE AFTER INDEX TO GET AFTER EACH NODE IN EACH PRODUCTION */
	generate_after_index();

	for(Production* prod : rules){
		follow_set[prod->get_LHS_name()] = follow(prod->get_LHS_name()) ;
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


void
First_Follow::generate_after_index() {
	for(Production* prod : rules){
		for(ProductionElement* elem : prod->get_RHS_elements()){
			vector<Node*> vec = elem->get_nodes() ;
			for(int i=0 ; i < (int)vec.size() ; i++){
				if(i+1 < (int)vec.size()){
					after_index[vec[i]->get_name()].push_back({vec[i+1],prod}) ;
				}else if(vec[i]->get_name() != prod->get_LHS_name()){
					after_index[vec[i]->get_name()].push_back({NULL,prod}) ;
				}
			}
		}
	}
}

bool
First_Follow::has_epsilon(set<Node> first) {
	for(Node n : first)
		if(n.is_epsilon())
			return true ;
	return false ;
}

set<Node>
First_Follow::follow(string node) {
	Node end = Node("$",Terminal) ;
	set<Node> ret ;
	vector<pair<Node* ,Production*>> after = after_index[node] ;

	/* MEMORIZING NODE */
	if(follow_set.find(node) != follow_set.end())
		return follow_set[node] ;

	for(int i=0 ; i < (int)after.size() ; i++){
		if(after[i].first == NULL){
			ret = follow(after[i].second->get_LHS_name()) ;
			return ret ;
		}
		ret = first_set[after[i].first->get_name()] ;
		if(has_epsilon(ret)){
			set<Node> res = follow(after[i].second->get_LHS_name()) ;
			for(Node n : res)ret.insert(n) ;
		}
	}

	/* Start Node has $ in Follow */
	if(node == rules[0]->get_LHS_name())
		ret.insert(end);


	/* Remove epsilons */
	set<Node> ret_without_ep ;
	for(Node n : ret)
		if(!n.is_epsilon())
			ret_without_ep.insert(n);

	/* MEMORIZING NODE */
	return follow_set[node] = ret_without_ep;

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
	map<string,set<Node>> first = f_f.get_first() , follow = f_f.get_follow() ;
	for(pair<string,set<Node>> p : first){
		cout << p.first << " : first { " ;
		int k = 0 ;
		for(Node n : p.second){
			cout << n.get_name() ;
			if(k < (int)p.second.size()-1 )
				cout << " , " ;
			k++ ;
		}
		cout << " }\n" ;
	}
	cout << endl ;
	for(pair<string,set<Node>> p : follow){
		cout << p.first << " : follow { " ;
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




