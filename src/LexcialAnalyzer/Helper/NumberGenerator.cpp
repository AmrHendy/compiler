/*
 * NumberGenerator.cpp
 * Created on: Mar 21, 2018
 * Author: Amr Hendy
 */


#include "../../../header/LexcialAnalyzer/Helper/NumberGenerator.h"

int NumberGenerator::number = 3;

NumberGenerator::NumberGenerator()
{
    // TODO Auto-generated constructor stub

}

NumberGenerator::~NumberGenerator()
{
    // TODO Auto-generated destructor stub
}

int NumberGenerator::getNextUniqueInt()
{
    return NumberGenerator::number++;
}

//this is called first by pattern processor to set the first priority value.
void NumberGenerator::setCurrentInt(int number)
{
    NumberGenerator::number = number;
}
