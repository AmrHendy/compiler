#include "Machine.h"

Machine::Machine(char basic_char){
	start = State();
	start.set_start(true);
	end = State();
	end.set_acceptance(true);
	start.add_transition(basic_char, end);
}


Machine::~Machine() {
	// TODO Auto-generated destructor stub
}


State Machine::get_start(void){
	return start;
}

State Machine::get_end(void){
	return end ;
}

void Machine::set_start(State start){
    Machine::start = start ;
}

void Machine::set_end(State start){
    Machine::end = end ;
}
