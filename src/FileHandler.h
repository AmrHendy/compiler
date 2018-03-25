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
#include <stdio.h>
#include <iostream>

using namespace std;

class FileHandler {
public:
	FileHandler();
	virtual ~FileHandler();
	static vector<string> readLanguageRules(string file_name);
	static string readUserProgram(string file_name);
	static void openNewTokenFile();
	static void append(string lexeme, string type);

};

#endif /* FILEHANDLER_H_ */
