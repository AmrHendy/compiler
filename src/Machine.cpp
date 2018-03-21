#include "Machine.h"

Machine::Machine(char basic_char){
	start = State();
	end = State();
	start.add_transition(basic_char, end);
}

Machine::Machine(){

}

Machine::~Machine() {
	// TODO Auto-generated destructor stub
}


State Machine::get_start(){
	return start;
}

State Machine::get_end(){
	return end ;
}

void Machine::set_start(State start){
    Machine::start = start ;
}

void Machine::set_end(State start){
    Machine::end = end ;
}
