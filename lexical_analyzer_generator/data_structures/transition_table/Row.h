#ifndef ROW_H_  /* Include guard */
#define ROW_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include "Row.h"
#include "Composite_State.h"

using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Row
{
public:
    /* attributes */
    Composite_State id ;
    map<char,Composite_State> transtions ;

public:
    /* constructor */
    Row(void);   // This is the constructor declaration
    Row(Composite_State id);   // This is the constructor declaration
    ~Row(void);  // This is the destructor: declaration

    /* interface functions */
    Composite_State get_id() ;

};


#endif // COMMANDS_H_
