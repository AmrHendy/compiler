/* INCLUDE GUARD */
/****************************************/
#ifndef FIRSTFOLLOW_H_
#define FIRSTFOLLOW_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include "../GrammerExtractor/Production.h"
#include "../GrammerExtractor/Node.h"
#include "../GrammerExtractor/GrammerParser.h"
#include <map>
#include <set>
#include <iostream>

/* CLASS DEFINITION */
/****************************************/
class FirstFollow {

private:
	/* CLASS ATTRIBUTES */
	vector<Production*> rules ;
	map<string,set<Node>> first_set,follow_set ;
	map<ProductionElement*,set<Node>> first_elem_set ;
	map<string , Production*> rules_index ;
	map<string , vector< pair< Production* , pair<ProductionElement*,int> > > > after_index;

public:
	/* CONSTRUCTOR AND DESTRUCTOR */
	FirstFollow(vector<Production*> rules);
	virtual ~FirstFollow();

public:
	/* INTERFACE METHODS */
	map<ProductionElement*,set<Node>> get_first_elem() ;
	map<string,set<Node>> get_follow() ;
	map<string,set<Node>> get_first();

private:
	/* UTILITY METHODS */
	void generate_rules_index() ;
	void generate_after_index() ;
	bool has_epsilon (set<Node> first) ;
	set<Node> follow(string node) ;
	set<Node> first(Node* node) ;
	set<Node> first(Production* prod) ;
	set<Node> first(ProductionElement* prod_elem) ;
};

#endif /* FIRSTFOLLOW_H_ */
