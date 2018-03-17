/*
 * compiler.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include <bits/stdc++.h>
#include "FileHandler.h"
#include "PatternProcessor.h"

using namespace std;

int main() {
	FileHandler fileHandler;
	vector<string> file_lines = fileHandler.readFile("input.txt");
	PatternProcessor patternProcessor(file_lines);
	vector<vector<string> > postfixRules = patternProcessor.getRules();
	return 0;
}
