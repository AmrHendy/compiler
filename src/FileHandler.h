/*
 * FileHandler.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class FileHandler {
public:
	FileHandler();
	virtual ~FileHandler();
	vector<string> readFile(string file_name);
};

#endif /* FILEHANDLER_H_ */
