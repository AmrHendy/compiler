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

	/* Kosrajo data */
	map<string,vector<string>> lis ;
	map<string,vector<string>> rlis ;
	vector<string> sta;
	// key = index belong to component = value
	map<string,string> component_index ;
	// all components indeces
	set<string> component_numbers ;
	//-------------------------------------
	set<string> visted;
	// all components
	vector<vector<string>> comps ;
	// current component
	vector<string> now ;

public:
	/* CONSTRUCTOR AND DESTRUCTOR */
	FirstFollow(vector<Production*> rules);
	virtual ~FirstFollow();

public:
	/* INTERFACE METHODS */
	map<ProductionElement*,set<Node>> get_first_elem();
	map<string,set<Node>> get_follow() ;
	map<string,set<Node>> get_first() ;
	set<string> follow_vis,first_vis ;

private:
	/* UTILITY METHODS */
	void generate_rules_index() ;
	void generate_after_index() ;
	bool has_epsilon (set<Node> first) ;
	set<Node> follow(string node) ;
	set<Node> first(Node* node) ;
	set<Node> first(Production* prod) ;
	set<Node> first(ProductionElement* prod_elem);
	void first_nrec(ProductionElement* prod_elem);

	/* Kosrajo data */
	void dfs(string num);
	void rdfs(string num);
	void print_comps();
	void generate_comps_index();
	void kosrajo();


};

#endif /* FIRSTFOLLOW_H_ */
