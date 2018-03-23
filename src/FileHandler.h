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
	static vector<string> readLanguageRules(string file_name);
	static string readUserProgram(string file_name);
};

#endif /* FILEHANDLER_H_ */
