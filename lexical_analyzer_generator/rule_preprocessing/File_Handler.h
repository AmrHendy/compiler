#ifndef FILE_HANDLER_H_  /* Include guard */
#define FILE_HANDLER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class File_Handler
{
	public:
	/* constructor */
    File_Handler(void);   // This is the constructor declaration
    ~File_Handler(void);  // This is the destructor: declaration

    /* interface functions */
    vector<string> read_file(string file_directory);
    
 
};


#endif // COMMANDS_H_