/*
 * LexicalAnalyzer.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef LEXICALANALYZER_H_
#define LEXICALANALYZER_H_

#include <string>
#include "../Tokenizer/Tokenizer.h"
#include "LexcialAnalyzerGenerator.h"

using namespace std;

class LexicalAnalyzer
{
public:
    LexicalAnalyzer(string language_rules_directory, string user_prog_directory);
    virtual ~LexicalAnalyzer();

    Token next_token();

private:
    Tokenizer tokenizer;
};

#endif /* LEXICALANALYZER_H_ */
