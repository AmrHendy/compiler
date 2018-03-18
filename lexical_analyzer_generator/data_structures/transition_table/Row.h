#ifndef ROW_H_  /* Include guard */
#define ROW_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "Composite_State.h"
#include <map>

/* CLASS DEFINITIONS */
/*********************************************/
class Row
{
	private:
	/* attributes */
	Composite_State id_state;
  	map<char,Composite_State> transitions;

	public:
	/* constructor */
    Row(Composite_State id_state);
    ~Row(void);

    /* interface functions */
    map<char,Composite_State> get_transitions(void);
    Composite_State get_id_state(void);

 
};


#endif