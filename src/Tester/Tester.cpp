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
	string output_file = "tests/ParsedGrammerTest.txt";
	vector<Production*> prods = GrammerParser::parse_grammer(file_name);
	Tester::printGrammerFile(output_file, prods);
}


void Tester::testFirstFollow(string file_name){
	string output_file = "tests/FirstFollow.txt";
	FileWriter::openNewFile(output_file);
	GrammerParser gp = GrammerParser() ;
	vector<Production*> rules = gp.parse_grammer(file_name);
	FirstFollow f_f = FirstFollow(rules) ;
	map<string,set<Node>> first = f_f.get_first();
	map<string,set<Node>> follow = f_f.get_follow() ;
	DerivationTable table = DerivationTable();

	SyntaxAnalyzerGenerator analyzer = SyntaxAnalyzerGenerator();

	FileWriter::append(output_file, "=========\n| First |\n=========");
	for(pair<string,set<Node>> p : first){
		string str = p.first + " = { ";
		int k = 0 ;
		for(Node n : p.second){
			str += n.get_name() ;
			if(k != p.second.size() - 1)
				str += " , ";
			k++ ;
		}
		str += " }\n=========================" ;
		FileWriter::append(output_file, str);
	}
	FileWriter::append(output_file, "==========\n| Follow |\n=========");
	for(pair<string,set<Node>> p : follow){
		string str = p.first + " = { ";
		int k = 0 ;
		for(Node n : p.second){
			str += n.get_name() ;
			if(k != p.second.size() - 1)
				str += " , ";
			k++ ;
		}
		str += " }\n========================= " ;
		FileWriter::append(output_file, str);
	}
}




void Tester::testElimination(){
	vector<Production*> rules = GrammerParser::parse_grammer("tests/helmy.txt");
	Tester::printGrammerFile("tests/helmy_out_before", rules);
    LeftRecursionElimination* obj1 = new LeftRecursionElimination(rules);
    rules = obj1->get_eliminated_rules();
    Tester::printGrammerFile("tests/helmy_after1.txt", rules);
    //cout << "Finished left Recursion\n";
    LeftFactoringElimination* obj2 = new LeftFactoringElimination(rules);
    rules = obj2->get_left_factor_rules();
    //cout << "Finished Left Factoring\n";
    Tester::printGrammerFile("tests/helmy_after2.txt", rules);
}


void Tester::printGrammerFile(string output_file, vector<Production*> rules){
	string line = "";
	for(Production* prod : rules){
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

	FileWriter::openNewFile(output_file);
	FileWriter::append(output_file, line);
}
