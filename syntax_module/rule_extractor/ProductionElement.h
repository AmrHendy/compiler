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
	virtual ~ProductionElement();
	void add_node(Node* node);
	vector<Node*> get_nodes();
	void print() ;

private:
	vector<Node*> nodes;
};

#endif /* PRODUCTIONELEMENT_H_ */
