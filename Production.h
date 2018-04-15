/*
 * Production.h
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <string>
#include <vector>
#include "ProductionElement.h"

using namespace std;

class Production {
public:
	Production();
	virtual ~Production();

private:
	string LHSNode;
	vector<ProductionElement> RHSNodes;
};

#endif /* PRODUCTION_H_ */
