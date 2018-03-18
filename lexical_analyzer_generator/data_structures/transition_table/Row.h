#ifndef ROW_H_  /* Include guard */
#define ROW_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Row
{
	private:
	/* attributes */
	Compl_state id ;
  	map<char,Compl_state> transtions ;

	public:
	/* constructor */
    Row(void);   // This is the constructor declaration
    ~Row(void);  // This is the destructor: declaration

    /* interface functions */
    
 
};


#endif // COMMANDS_H_