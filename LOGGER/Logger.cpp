/*
 * Logger.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: abdelrhman
 */

#include "Logger.h"

ofstream Logger::out = ofstream("log.txt",ofstream::out) ;

Logger::Logger() {
	// TODO Auto-generated ructor stub
	}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

void
Logger::print_string( string s){
	out << s;
}
