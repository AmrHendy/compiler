#include "Machine.h"

Machine::Machine(){
	end = new State(-1);
	start = new State(-1);
}

Machine::Machine(char basic_char){
	start = new State(NumberGenerator::getNextUniqueInt());
	end = new State(NumberGenerator::getNextUniqueInt());
	start->add_transition(basic_char, end);
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

void
Machine::print(){
	Logger::logger.print_string("Machine { \nstart : ");
	start->print();
	Logger::logger.print_string("\nend : ");
	end->print();
}

