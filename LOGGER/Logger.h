/*
 * Logger.h
 *
 *  Created on: Mar 25, 2018
 *      Author: abdelrhman
 */

#ifndef LOGGER_LOGGER_H_
#define LOGGER_LOGGER_H_

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std ;

enum Files{ graph_file = 0 , log_file = 1  , tables_file = 2 } ;

namespace patch
{
    template < typename T > std::string to_string(  T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

class Logger {
public:
	Logger();
	virtual ~Logger();
	static Logger logger ;
	static void print_string(string s ,  Files file_name);
private:
	static ofstream out1 , out2 , out3 ;
};

#endif /* LOGGER_LOGGER_H_ */
