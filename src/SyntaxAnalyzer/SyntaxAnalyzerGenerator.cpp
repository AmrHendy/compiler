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
SyntaxAnalyzerGenerator::generate_derivation_table(vector<Production*> rules)
{
	DerivationTable table = DerivationTable() ;
	bool err = false ;

	/* GENERATING FIRST & FOLLOW */
	map<ProductionElement*,set<Node>> first_elem ;
	map<string,set<Node>> follow ;

	FirstFollow f_f = FirstFollow(rules) ;
	follow = f_f.get_follow();
	first_elem = f_f.get_first_elem();

	/* GENERATE TABLE AFTER FIRST FOLLOW IS DONE */
	for(Production* prod : rules){
		for(ProductionElement* elem : prod->get_RHS_elements()){
			set<Node> first_set = first_elem[elem];
			set<Node> follow_set = follow[prod->get_LHS_name()];
			for(Node n : first_set){
				if(!n.is_epsilon())
					err = table.add_transition(prod->get_LHS_name() , n.get_name() , elem) ;
				if(err)
					return DerivationTable();
			}
			if(has_epsilon(first_set)){
				for(Node n : follow_set){
					err = table.add_transition(prod->get_LHS_name() , n.get_name() , elem) ;
					if(err)
						return DerivationTable();
				}
			}
		}
	}
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

/* LOCAL TEST */
/****************************************/
/*int main(){
	GrammerParser gp = GrammerParser() ;
	vector<Production*> rules = gp.parse_grammer("CFG.txt");
	Derivation_Table table = Syntax_Analyzer_Generator::generate_derivation_table(rules) ;
	table.print();
}*/

