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
	Production(string LHSName);
	virtual ~Production();
	void add_element(ProductionElement *elem);
	void add_element(vector<ProductionElement*> elems);

	string get_LHS_name();
	vector<ProductionElement*> get_RHS_elements();

private:
	string LHSNode;
	vector<ProductionElement*> RHS;
};

#endif /* PRODUCTION_H_ */
