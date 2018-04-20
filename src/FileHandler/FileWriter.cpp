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

void FileWriter::append(string file_name, string message){
	ofstream outfile(file_name.c_str(), ios_base::app);
	outfile << message << endl;
}

void FileWriter::openNewFile(string file_name){
	remove(file_name.c_str());
}
