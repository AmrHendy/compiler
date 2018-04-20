/*
 * FileHandler.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef FILEREADER_H_
#define FILEREADER_H_

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class FileReader
{
public:
    FileReader();
    virtual ~FileReader();
    static vector<string> readLanguageRules(string file_name);
    static string readUserProgram(string file_name);
};

#endif /* FILEREADER_H_ */
