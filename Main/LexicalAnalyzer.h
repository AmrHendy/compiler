/*
 * LexicalAnalyzer.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef MAIN_LEXICALANALYZER_H_
#define MAIN_LEXICALANALYZER_H_

#include <string>

#include "LexcialAnalyzerGenerator.h"
#include "../Tokenizer/Tokenizer.h"

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

#endif /* MAIN_LEXICALANALYZER_H_ */
