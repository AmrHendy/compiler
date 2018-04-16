/*
 * PatternProcessor.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef PATTERNPROCESSOR_H_
#define PATTERNPROCESSOR_H_

#include "Rule.h"
#include <vector>
#include <string>

using namespace std;

class PatternProcessor
{
public:
    PatternProcessor(string fileName);
    virtual ~PatternProcessor();
    vector<Rule> getRules();

private:
    vector<string> file_lines;
};


#endif /* PATTERNPROCESSOR_H_ */
