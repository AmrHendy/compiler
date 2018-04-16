/*
 * FirstFollow.h
 *
 *  Created on: Apr 16, 2018
 *      Author: abdelrhman
 */

#ifndef SRC_SYNTAX_MODULE_DERIVATION_TABLE_GENERATOR_FIRSTFOLLOW_H_
#define SRC_SYNTAX_MODULE_DERIVATION_TABLE_GENERATOR_FIRSTFOLLOW_H_

#include "../rule_extractor/Production.h"
#include "../rule_extractor/Node.h"
#include <map>
#include <set>

class First_Follow {
public:
	First_Follow(vector<Production*> rules);
	virtual ~First_Follow();
	map<string,set<Node>> get_first() ;
	map<string,set<Node>> get_follow() ;

private:
	void generate_rules_index() ;
	set<Node> first(Node* node) ;
	set<Node> first(Production* prod) ;
	set<Node> first(ProductionElement* prod_elem) ;

private:
	vector<Production*> rules ;
	map<string,set<Node>> first_set,follow_set ;
	map<string , Production*> rules_index ;
};

#endif /* SRC_SYNTAX_MODULE_DERIVATION_TABLE_GENERATOR_FIRSTFOLLOW_H_ */
