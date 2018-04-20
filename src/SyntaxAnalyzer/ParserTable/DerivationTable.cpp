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
	cout << non_terminal << " " << terminal << " " << Table[{non_terminal,terminal}]->get_format() << " " << Table[{non_terminal,terminal}]->get_name() << endl;
	cout << non_terminal << " " << terminal << " " << rule->get_format() << " " << Table[{non_terminal,terminal}]->get_name() << endl;
	cout << "Table suffers ambiguity" << endl ;
	return true ;
}

ProductionElement* DerivationTable::get_transition (string non_terminal , string terminal) {
	if(Table.find({non_terminal,terminal}) != Table.end())
		return Table[{non_terminal, terminal}] ;
	else
		return new ProductionElement("Error");
}

void
DerivationTable::print(string file_name){
	vector<vector<string> > table(non_terminals.size() + 1);
	int row_index = 0;
	table[row_index].push_back("NT Name");
	for(string str : terminals){
		table[row_index].push_back(str);
	}

	row_index++;
	for(string non_terminal : non_terminals){
		string str;
		table[row_index].push_back(non_terminal);
		for(string terminal : terminals){
			if(Table.find({non_terminal, terminal}) != Table.end()){
				ProductionElement* elem = Table[{non_terminal, terminal}];
				if(elem->is_synchronize()){
					str = "SYNC";
				}
				else{
					str = elem->get_format();
				}
			}
			else{
				str = "Error";
			}
			table[row_index].push_back(str);
		}
		row_index++;
	}


	// finding max width for the column to fit the data
	vector<int> width;
	for(int col_index = 0; col_index <= terminals.size(); col_index++){
		int maxx = 0;
		for(int index = 0; index < table.size(); index++){
			maxx = max((int)table[index][col_index].size(), maxx);
		}
		width.push_back(maxx + 2);
	}



	FileWriter::openNewFile(file_name);
	for(vector<string> row : table){
		// print row separator
		string str = "+";
		for(int w : width){
			for(int ind = 0; ind < w; ind++) str += '-';
			str += "+";
		}
		FileWriter::append(file_name, str);

		// print the row
		str = "|";
		for(int index = 0; index < row.size(); index++){
			str += row[index];
			for(int rest = row[index].size(); rest < width[index]; rest++){
				str += " ";
			}
			str += "|";
		}
		FileWriter::append(file_name, str);
	}

	// print row separator
	string str = "+";
	for(int w : width){
		for(int ind = 0; ind < w; ind++) str += '-';
		str += "+";
	}
	FileWriter::append(file_name, str);
}

// need to be implemented
string DerivationTable::get_non_terminal_start(){
	string str;
	return str;
}


void DerivationTable::set_terminals(set<string> terminal_names){
	terminals = terminal_names;
}

void DerivationTable::set_non_terminals(set<string> non_terminal_names){
	non_terminals = non_terminal_names;
}
