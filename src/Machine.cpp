#include "Machine.h"

Machine::Machine(char basic_char){
	start = new State(NumberGenerator::getNextUniqueInt());
	end = new State(NumberGenerator::getNextUniqueInt());
	start->add_transition(basic_char, end);
}

Machine::Machine(){

}

Machine::~Machine() {
	// TODO Auto-generated destructor stub
}


State* Machine::get_start(){
	return start;
}

State* Machine::get_end(){
	return end ;
}

void Machine::set_start(State* start){
    Machine::start = start ;
}

void Machine::set_end(State* end){
    Machine::end = end;
}
