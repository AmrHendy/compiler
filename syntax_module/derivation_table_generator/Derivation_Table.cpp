/* INCLUDE HEADER */
/****************************************/
#include "Derivation_Table.h"


/* IMPLEMENT CONSTRUCTOR */
/****************************************/
Derivation_Table::Derivation_Table(void){

}

Derivation_Table::~Derivation_Table(void){

}

/* IMPLEMENT INTERFACE METHODS */
/****************************************/
bool
Derivation_Table::add_transition (string non_terminal , string terminal , ProductionElement* rule) {
	if(Table.find({non_terminal,terminal}) == Table.end()){
		Table[{non_terminal,terminal}] = rule ;
		return false ;
	}
	cout << "Table suffers ambiguity" << endl ;
	return true ;
}

ProductionElement* Derivation_Table::get_transition (string non_terminal , string terminal) {
	if(Table.find({non_terminal,terminal}) != Table.end())
		return Table[{non_terminal,terminal}] ;
	else
		return NULL ;
}

void
Derivation_Table::print(void){
	for(pair<pair<string,string>,ProductionElement*> p : Table){
		cout << p.first.first << " >>  " << p.first.second << " (" ;
		p.second->print() ;
		cout << ") " << endl ;
	}
}

