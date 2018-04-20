/*
 * Tester.cpp
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#include "../../header/Tester/Tester.h"

Tester::Tester() {
	// TODO Auto-generated constructor stub

}

Tester::~Tester() {
	// TODO Auto-generated destructor stub
}

void Tester::testGrammerParser(string file_name){
	vector<Production*> prods = GrammerParser::parse_grammer(file_name);
	string line = "";
	for(Production* prod : prods){
		line += "LHSNode = " + prod->get_LHS_name() + "\n";
		for(int index = 0; index < prod->get_RHS_elements().size(); index++){
			line += "elem";
			line += "  =  ";

			for(Node* node : prod->get_RHS_elements()[index]->get_nodes()){
				line += "{ " + node->get_name() + " , " + (node->get_type() == NodeType::NonTerminal ? "NT" : "T") + " }";
				line += " $$ ";
			}
			line += "\n";
		}
		line += "==========================================================================\n";
	}

	FileWriter::openNewFile("ParsedGrammerTest.txt");
	FileWriter::append("ParsedGrammerTest.txt", line);
}


void Tester::testFirstFollow(string file_name){
	string output_file = "FirstFollow.txt";
	FileWriter::openNewFile(output_file);
	GrammerParser gp = GrammerParser() ;
	vector<Production*> rules = gp.parse_grammer(file_name);
	FirstFollow f_f = FirstFollow(rules) ;
	map<string,set<Node>> first = f_f.get_first();
	map<string,set<Node>> follow = f_f.get_follow() ;
	DerivationTable table = DerivationTable();

	SyntaxAnalyzerGenerator analyzer = SyntaxAnalyzerGenerator();

	FileWriter::append(output_file, "\t\tFirst");
	for(pair<string,set<Node>> p : first){
		string str = p.first + " = { ";
		int k = 0 ;
		for(Node n : p.second){
			str += n.get_name() ;
			if(k != p.second.size() - 1)
				str += " , ";
			k++ ;
		}
		str += " }" ;
		FileWriter::append(output_file, str);
	}
	FileWriter::append(output_file, "========================================================================");
	FileWriter::append(output_file, "\t\tFollow");
	for(pair<string,set<Node>> p : follow){
		string str = p.first + " = { ";
		int k = 0 ;
		for(Node n : p.second){
			str += n.get_name() ;
			if(k != p.second.size() - 1)
				str += " , ";
			k++ ;
		}
		str += " }\n\n ========================= " ;
		FileWriter::append(output_file, str);
	}

	analyzer.generate_derivation_table(rules) ;
}
