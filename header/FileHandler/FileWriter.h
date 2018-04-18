/*
 * FileWriter.h
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#ifndef FILEWRITER_H_
#define FILEWRITER_H_

#include <string>
#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;

class FileWriter {
public:
	FileWriter();
	virtual ~FileWriter();

	static void append(string file_name, string message);
	static void openNewFile(string file_name);
};

#endif /* FILEWRITER_H_ */
