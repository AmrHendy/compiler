/*
 * Token.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

using namespace std;

class Token
{
public:
    Token(string type,
          string pattern,
          string lexeme);

    virtual ~Token();

    string getType(void);

    string getLexeme(void);

    string getPattern(void);

private:
    string type, pattern, lexeme;
};
#endif /* TOKEN_H_ */


//~ Formatted by Jindent --- http://www.jindent.com
