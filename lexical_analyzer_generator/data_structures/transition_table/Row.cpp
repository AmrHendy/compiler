/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include "Row.h"

using namespace std;

/* CONSTRUCTOR */
/*********************************************/
Row::Row(Composite_State id)
{
    this-> id = id ;
}

Row::~Row(void)
{

}

/* INTERFACE METHODS */
/*********************************************/
Composite_State Row::get_id(){
    return this -> id ;
}
