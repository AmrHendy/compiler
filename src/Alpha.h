/*
 * Alphabet.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef ALPHA_H_
#define ALPHA_H_

#include <set>

using namespace std;

class Alpha {
public:
	Alpha();
	virtual ~Alpha();
	static set<char> getAlphabet();
	static void setAlphabet(set<char> alphaa);
	static void insertAlphabet(char ch);

	static set<char> alpha;
	static int num;
};

#endif /* ALPHABET_H_ */
