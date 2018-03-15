/* IMPORT LIBRARIES */
/*********************************************/
#include "Machine.h"
#include "State.h"
#include <list>


using namespace std ;

/* CONSTRUCTOR */
/*********************************************/
Machine::Machine(char character)
{
   /* machine with '\0' won't have edge from start to end with epsilon */
   if(character != '\0')
        this->start.add_transition({this->end,character});
}

Machine::~Machine(void)
{

}

/* SETTERS AND GETTERS */
/*********************************************/
State Machine::get_start(void)
{
	return this-> start ;
}

State Machine::get_end(void)
{
	return this-> end ;
}

void Machine::add_transition_start(pair<State, char> transition)
{
    this->start.add_transition(transition) ;
}

void Machine::add_transition_end(pair<State, char> transition)
{
    this->end.add_transition(transition) ;
}

void Machine::set_start(State start)
{
    this->start = start ;
}

void Machine::set_end(State start)
{
    this->end = end ;
}


/* INTERFACE METHODS */
/*********************************************/

/*

						--->	m1(start) ------> m1(end) -------------------
						|													|
						|													V
	n_machine(start)----												n_machine(end)
						|													^
						|													|
						--->	this(start) ------> this(end) ---------------
*/
Machine Machine::operator | (Machine& m){
	// create new machine
	Machine n_machine('\0') ;

	// connect new machine start to two starts of two machines
	n_machine.add_transition_start({this->start,'\0'}) ;
	n_machine.add_transition_start({m.start,'\0'}) ;

	// connect two ends of two machines to new machine end
	m.add_transition_end({n_machine.end,'\0'}) ;
	this->add_transition_end({n_machine.end,'\0'}) ;

	return n_machine ;
}

/*

	    (n_machine(start) & this(start)) ------> (this(end)  &  m(start)) ------> (m(end) & n_machine(end))

*/
Machine Machine::operator * (Machine& m){
	// create new machine
	Machine n_machine('\0') ;
	// start of new machine is start of first machine
	n_machine.start = this->start ;
	// end of first machine is start of second machine
	this->end = m.start ;
	// end of new machine is end of second machine
	n_machine.end = m.end  ;

	return n_machine ;
}

/*
											E
									-----------------
									|				|
						E			V		a		|		E
	n_machine(start) ------>	m(start) ------> m(end) ------>  n_machine(end)
		|																^
		|																|
		|																|
		-----------------------------------------------------------------
										E
*/

Machine Machine::kleen_closure (Machine& m){
	// create new machine
	Machine n_machine('\0') ;
	n_machine.add_transition_start({n_machine.get_end(),'\0'}) ;
	n_machine.add_transition_start({m.get_start(),'\0'}) ;
	m.add_transition_end({m.get_start(),'\0'}) ;
	m.add_transition_end({n_machine.get_end(),'\0'}) ;
	return n_machine ;
}


Machine Machine::postive_closure(Machine& m){
    Machine closure_machine = kleen_closure(m) ;
    Machine n_machine = m * closure_machine ;
    return n_machine ;
}

