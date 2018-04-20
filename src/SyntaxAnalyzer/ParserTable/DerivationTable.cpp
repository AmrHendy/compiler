/* INCLUDE HEADER */
/****************************************/
#include "../../../header/SyntaxAnalyzer/ParserTable/DerivationTable.h"


/* IMPLEMENT CONSTRUCTOR */
/****************************************/
DerivationTable::DerivationTable(void){

}

DerivationTable::~DerivationTable(void){

}

/* IMPLEMENT INTERFACE METHODS */
/****************************************/
bool
DerivationTable::add_transition (string non_terminal , string terminal , ProductionElement* rule) {
	if(Table.find({non_terminal,terminal}) == Table.end()){
		Table[{non_terminal,terminal}] = rule ;
		return false ;
	}
	cout << "Table suffers ambiguity" << endl ;
	return true ;
}

ProductionElement* DerivationTable::get_transition (string non_terminal , string terminal) {
	if(Table.find({non_terminal,terminal}) != Table.end())
		return Table[{non_terminal,terminal}] ;
	else
		return NULL ;
}

void
DerivationTable::print(void){
	for(pair<pair<string,string>,ProductionElement*> p : Table){
		cout << p.first.first << " >>  " << p.first.second << " (" ;
		p.second->print() ;
		cout << ") " << endl ;
	}
}

// need to be implemented
string DerivationTable::get_non_terminal_start(){
	string str;
	return str;
}
