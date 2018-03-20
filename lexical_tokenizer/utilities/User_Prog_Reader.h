#ifndef USER_PROG_READER_H_  /* Include guard */
#define USER_PROG_READER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <fstream>
#include <string>
#include "Composite_State.h"

/* CLASS DEFINITIONS */
/*********************************************/
class User_Prog_Reader
{
	public:
	/* attributes */
	string user_program;
	/* pointers */
	int current_index = 0;
	int last_acceptance_index;
	int prog_size;
	/* buffers */
	char current_char;
	string token_buffer;
	/* current state pointer */
	Composite_State current_state;
	Composite_State last_acceptance_state;

	/* constructor */
    User_Prog_Reader(string user_program_directory);
    ~User_Prog_Reader(void);

    /* interface functions */
    Token read_file(void);
    
 
};


#endif