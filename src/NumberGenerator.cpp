/*
 * NumberGenerator.cpp
 * Created on: Mar 21, 2018
 * Author: Amr Hendy
 */

#include "NumberGenerator.h"

int NumberGenerator::number = 1;

NumberGenerator::NumberGenerator() {
	// TODO Auto-generated constructor stub

}

NumberGenerator::~NumberGenerator() {
	// TODO Auto-generated destructor stub
}

int NumberGenerator::getNextUniqueInt(){
	return NumberGenerator::number++;
}

void NumberGenerator::setCurrentInt(int number){
	NumberGenerator::number = number;
}
