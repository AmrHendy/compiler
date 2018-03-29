/*
 * Logger.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: abdelrhman
 */

#include "Logger.h"

ofstream Logger::out1 = ofstream("log.lg",ofstream::out) ;
ofstream Logger::out2 = ofstream("graph.gv",ofstream::out) ;
ofstream Logger::out3 = ofstream("tables.tb",ofstream::out) ;

Logger::Logger() {
	// TODO Auto-generated ructor stub
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

void
Logger::print_string( string s , Files file_name){
	if(file_name == Files::graph_file)
		out2 << s ;
	else if(file_name == Files::log_file)
		out1 << s;
	else if(file_name == Files::tables_file)
		out3 << s ;
}

