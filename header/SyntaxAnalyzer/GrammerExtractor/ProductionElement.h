/*
 * ProductionElement.h
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#ifndef PRODUCTIONELEMENT_H_
#define PRODUCTIONELEMENT_H_

#include "Node.h"
#include <vector>

using namespace std;

class ProductionElement {
public:
	ProductionElement();
	ProductionElement(string name);
	virtual ~ProductionElement();
	void add_node(Node* node);
	vector<Node*> get_nodes();
	void print() ;
	bool is_synchronize();
	bool is_empty();
	string get_format();
	string get_name();
	void remove_first_node();

private:
	vector<Node*> nodes;
	string name;
};

#endif /* PRODUCTIONELEMENT_H_ */
