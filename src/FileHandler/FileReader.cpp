/*
 * FileHandler.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "../../header/FileHandler/FileReader.h"

using namespace std;

FileReader::FileReader()
{
    // TODO Auto-generated constructor stub

}

FileReader::~FileReader()
{
    // TODO Auto-generated destructor stub
}

vector<string> FileReader::readLanguageRules(string file_name)
{
    ifstream input_file (file_name.c_str(), ifstream::in);
    vector<string> all_lines;
    string input_line;
    if(input_file.is_open())
    {
        while(getline(input_file, input_line))
        {
            all_lines.push_back(input_line);
        }
    }
    return all_lines;
}

string FileReader::readUserProgram(string file_name)
{
    vector<string> vectorLines = FileReader::readLanguageRules(file_name);
    string result;
    for(string s : vectorLines)result += s;
    return result;
}
