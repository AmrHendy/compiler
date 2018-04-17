/*
 * FileWriter.cpp
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#include "../../header/FileHandler/FileWriter.h"

FileWriter::FileWriter() {
	// TODO Auto-generated constructor stub

}

FileWriter::~FileWriter() {
	// TODO Auto-generated destructor stub
}

void FileWriter::write(string file_name, string message){
	ofstream outfile(file_name.c_str());
	// if we want to append to existing file
	// outfile.open(file_name.c_str(), ios_base::app);
	outfile << message;
}

