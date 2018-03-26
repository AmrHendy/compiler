/*
 * Alphabet.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#include "Alpha.h"


set<char> Alpha::alpha = {'\0'};

Alpha::Alpha() {
	// TODO Auto-generated constructor stub
}

Alpha::~Alpha() {
	// TODO Auto-generated destructor stub
}

set<char> Alpha::getAlphabet(){
	return alpha;
}

void Alpha::setAlphabet(set<char> alphaa){
	Alpha::alpha = alphaa;
}

void Alpha::insertAlphabet(char ch){
	Alpha::alpha.insert(ch);
}
