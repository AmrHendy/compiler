/*
 * Node.h
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#ifndef NODE_H_
#define NODE_H_

#include <string>
enum NodeType { Terminal, NonTerminal };

using namespace std;

class Node {
public:
	Node();
	virtual ~Node();

private:
	string name;
	NodeType type;
};

#endif /* NODE_H_ */
