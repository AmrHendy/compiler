/*
 * PatternProcessor.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef PATTERNPROCESSOR_H_
#define PATTERNPROCESSOR_H_

#include <vector>
#include <string>

using namespace std;

class PatternProcessor {
public:
	PatternProcessor(vector<string> file_lines);
	virtual ~PatternProcessor();
	vector<vector<string> > getRules();

private:
	vector<string> file_lines;
};


#endif /* PATTERNPROCESSOR_H_ */
