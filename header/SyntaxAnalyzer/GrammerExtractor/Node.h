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
	Node(string name, NodeType type);
	virtual ~Node();

	string get_name();
	NodeType get_type();

	bool is_epsilon();
	bool is_dollar();

	bool operator == (const Node n)const;
	bool operator < (const Node n)const;
	bool operator > (const Node n)const;

private:
	string name;
	NodeType type;
};

#endif /* NODE_H_ */
