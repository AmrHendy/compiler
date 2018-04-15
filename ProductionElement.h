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

private:
	vector<Node> nodes;
};

#endif /* PRODUCTIONELEMENT_H_ */
