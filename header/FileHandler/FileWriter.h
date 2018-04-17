/*
 * FileWriter.h
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#ifndef FILEWRITER_H_
#define FILEWRITER_H_

#include <string>
#include <fstream>

using namespace std;

class FileWriter {
public:
	FileWriter();
	virtual ~FileWriter();

	static void write(string file_name, string message);
};

#endif /* FILEWRITER_H_ */
