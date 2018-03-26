#ifndef ROW_H_  /* Include guard */
#define ROW_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "CompositeState.h"
#include <map>

/* CLASS DEFINITIONS */
/*********************************************/
class Row
{

	public:
		/* constructor */
		Row(CompositeState* id_state);
		virtual ~Row(void);

		/* interface functions */
		CompositeState* get_transition(char input);
		void set_transition(char input , CompositeState*);

		CompositeState* get_id_state(void);

		void insert_transition(char input_char, CompositeState* s);

		void print() ;

	private:
		/* attributes */
		CompositeState* id_state;
		map<char,CompositeState*> transitions;
};


#endif
