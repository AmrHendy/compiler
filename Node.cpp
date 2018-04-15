/*
 * Node.cpp
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#include "Node.h"

Node::Node(string name, NodeType type) {
	Node::name = name;
	Node::type = type;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

string Node::get_name(){
	return name;
}

NodeType Node::get_type(){
	return type;
}
