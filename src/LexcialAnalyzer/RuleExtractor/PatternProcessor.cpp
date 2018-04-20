/*
 * PatternProcessor.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "../../../header/LexcialAnalyzer/RuleExtractor/PatternProcessor.h"
#include "../../../header/LexcialAnalyzer/RuleExtractor/RuleExtractor.h"
#include "../../../header/FileHandler/FileReader.h"
#include "../../../header/LexcialAnalyzer/Helper/NumberGenerator.h"

using namespace std;

PatternProcessor::PatternProcessor(string fileName)
{
    file_lines = FileReader::readLanguageRules(fileName);
}

PatternProcessor::~PatternProcessor()
{
    // TODO Auto-generated destructor stub
}

vector<Rule> PatternProcessor::getRules()
{
    NumberGenerator::setCurrentInt(3);
    RuleExtractor ruleExtractor;
    vector<Rule> all_rules;
    for(string str : file_lines)
    {
        ruleExtractor.extractRule(str);
    }
    return ruleExtractor.getAllRules();
}
