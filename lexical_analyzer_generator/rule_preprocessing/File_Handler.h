#ifndef FILE_HANDLER_H_  /* Include guard */
#define FILE_HANDLER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include <studio.h>
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
    void read_file(char* file_name);
    
 
};


#endif // COMMANDS_H_