/* INCLUDE HEADER */
/****************************************/
#include "../../header/SyntaxAnalyzer/SyntaxAnalyzerGenerator.h"

/* IMPLEMENT CONSTRUCTOR */
/****************************************/
SyntaxAnalyzerGenerator::SyntaxAnalyzerGenerator()
{

}

SyntaxAnalyzerGenerator::~SyntaxAnalyzerGenerator()
{

}

/* IMPLEMENT INTERFACE METHODS */
/****************************************/
DerivationTable
SyntaxAnalyzerGenerator::generate_derivation_table(vector<Production*> rules, string output_table_file)
{
	DerivationTable table = DerivationTable() ;

	bool err = false ;

	/* GENERATING FIRST & FOLLOW */
	map<ProductionElement*,set<Node>> first_elem ;
	map<string,set<Node>> follow ;

	FirstFollow f_f = FirstFollow(rules);
	follow = f_f.get_follow();
	first_elem = f_f.get_first_elem();

	set<string> terminals, non_terminals;

	/* GENERATE TABLE AFTER FIRST FOLLOW IS DONE */
	for(Production* prod : rules){
		non_terminals.insert(prod->get_LHS_name());
		set<Node> follow_set = follow[prod->get_LHS_name()];
		for(ProductionElement* elem : prod->get_RHS_elements()){
			set<Node> first_set = first_elem[elem];
			for(Node n : first_set){
				if(!n.is_epsilon()){
					err = table.add_transition(prod->get_LHS_name(), n.get_name() , elem) ;
					terminals.insert(n.get_name());
				}
				if(err){
					FileWriter::openNewFile(output_table_file);
					return DerivationTable();
				}
			}

			if(has_epsilon(first_set)){
				for(Node n : follow_set){
					if(first_set.count(n) != 0) continue;
					err = table.add_transition(prod->get_LHS_name(), n.get_name() , elem) ;
					terminals.insert(n.get_name());
					if(err){
						FileWriter::openNewFile(output_table_file);
						return DerivationTable();
					}
				}
			}
		}

		// make synch
		for(Node n : follow_set){
			ProductionElement* prodd = table.get_transition(prod->get_LHS_name(), n.get_name());
			if(prodd->is_empty()){
				ProductionElement* element = new ProductionElement("SYNC");
				table.add_transition(prod->get_LHS_name(), n.get_name(), element) ;
			}
		}
	}

	table.set_terminals(terminals);
	table.set_non_terminals(non_terminals);
	table.set_non_terminal_start(rules[0]->get_LHS_name());

	table.print(output_table_file);
	return table ;
}

/* UTILITY METHODS */
/****************************************/
bool
SyntaxAnalyzerGenerator::has_epsilon(set<Node> nodes){
	for(Node n : nodes)
		if(n.is_epsilon())
			return true ;
	return false ;
}

bool
SyntaxAnalyzerGenerator::has_dollar(set<Node> nodes){
	for(Node n : nodes)
		if(n.is_dollar())
			return true ;
	return false ;
}
