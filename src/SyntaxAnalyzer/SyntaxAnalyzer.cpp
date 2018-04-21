/* INCLUDE HEADER */
/****************************************/
#include "../../header/SyntaxAnalyzer/SyntaxAnalyzer.h"

/* IMPLEMENT CONSTRUCTOR */
/****************************************/
SyntaxAnalyzer::SyntaxAnalyzer(void)
{

}

SyntaxAnalyzer::~SyntaxAnalyzer(void)
{

}

/* INTERFACE METHODS */
/****************************************/
void
SyntaxAnalyzer::analyze_prog(vector<Token> user_prog, DerivationTable derivation_table)
{
	string derivation_file = "derivation.txt";

	/* construction stack */
	stack<Node*> stack;
	/* get first transition in table */
	string start_nt_node = derivation_table.get_non_terminal_start();
	stack.push(new Node(start_nt_node, NodeType::NonTerminal));

	vector<Node*> current_derivation;
	current_derivation.push_back(new Node(start_nt_node, NodeType::NonTerminal));

	int token_index = 0;
	while(token_index < user_prog.size() && !stack.empty()){
		Node* curr = stack.top();
		string current_symbol = "'" + user_prog[token_index].getType() + "'";

		if(curr->get_type() == NodeType::Terminal){
			if(curr->get_name() == current_symbol){
				//match
			}
			else{
				//error
				string error_message = "Error: missing " + curr->get_name().substr(1, curr->get_name().size() - 2)
										+ " !! unmatched terminal is inserted";
				FileWriter::append(derivation_file, error_message);
				stack.pop();
			}
		}
		else{
			ProductionElement* prod_elem = derivation_table.get_transition(curr->get_name(), current_symbol);
			if(prod_elem->is_empty()){
				//error
				string error_message = "Error: discard " + user_prog[token_index].getType();
				FileWriter::append(derivation_file, error_message);
				token_index++;
			}
			else if(prod_elem->is_synchronize()){
				stack.pop();
			}
			else{
				//make left most derivation

				vector<Node*> nodes = prod_elem->get_nodes();
				stack.pop();
				for(int index = nodes.size(); index >= 0; index--){
					if(!nodes[index]->is_epsilon()){
						stack.push(nodes[index]);
					}
				}

				vector<Node*> temp;
				bool matched = false;
				for(Node* node : current_derivation){
					if(node->get_name() == curr->get_name() && !matched){
						matched = true;
						for(Node* nodee : prod_elem->get_nodes()){
							temp.push_back(nodee);
						}
					}
					else{
						temp.push_back(node);
					}
				}
				current_derivation.clear();
				current_derivation = temp;

				string output_line = "";
				for(Node* node : current_derivation){
					output_line += node->get_name() + " ";
				}
				FileWriter::append(derivation_file, output_line);
			}
		}
	}
}
