/* INCLUDE HEADER */
/*********************************************/
#include "User_Prog_Reader.h"

/* MEMBER FUNCTION IMPLEMENTATION */
/*********************************************/
User_Prog_Reader::User_Prog_Reader(string user_program_directory);
{
   this->user_program_directory = user_program_directory;
}

User_Prog_Reader::~User_Prog_Reader(void)
{
   /* nothing */
}


/* INTERFACE FUNCTIONS */
/*********************************************/
string
read_file(void)
{
	string result("");
	/* open file with read flag */
	ifstream input_file (file_name.c_str(), ifstream::in);
	/* read from file */
	string input_line;
	if(input_file.is_open())
	{
		while(getline(input_file, input_line))
		{
			result = result + input_line;
		}
	}
	/* close file */
	return result;
}