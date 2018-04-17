/*
 * NumberGenerator.h
 * Created on: Mar 21, 2018
 * Author: Amr Hendy
 */

#ifndef NUMBERGENERATOR_H_
#define NUMBERGENERATOR_H_

class NumberGenerator
{
public:
    NumberGenerator();
    virtual ~NumberGenerator();
    static int getNextUniqueInt();
    static void setCurrentInt(int number);

    static int number;
};

#endif /* NUMBERGENERATOR_H_ */
