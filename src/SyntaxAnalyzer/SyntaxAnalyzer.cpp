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
	/* terminate the input program by dollar. */
	user_prog.push_back(Token("$", "$", "$"));

	vector<string> output_file;
	/* construction stack */
	stack<Node*> stack;
	/* add dollar at first of stack. */
	stack.push(new Node("$", NodeType::Terminal));
	/* get first transition in table */
	string start_nt_node = derivation_table.get_non_terminal_start();
	stack.push(new Node(start_nt_node, NodeType::NonTerminal));
	output_file.push_back(stack_to_string(stack));

	int token_index = 0;
	while(token_index < user_prog.size() && !stack.empty()){
		Node* curr = stack.top();
		string current_symbol = "'" + user_prog[token_index].getType() + "'";

		if(curr->get_type() == NodeType::Terminal){
			if(curr->get_name() == current_symbol){
				/* check if we finished the input. */
				if(curr->get_name() == "$"){
					break;
				}
				/* current token matching first non-terminal */
				stack.pop();
				token_index++;
			}
			else{
				/* unidentified error type, hence skip current token. */
				string error_message = "Error: missing " + curr->get_name().substr(1, curr->get_name().size() - 2)
										+ " !! unmatched terminal is inserted";
				output_file.push_back(error_message);
				stack.pop();
			}
		}
		else{
			ProductionElement* prod_elem = derivation_table.get_transition(curr->get_name(), current_symbol);
			if(prod_elem->is_empty()){
				/* Error Transition, remove current token */
				string error_message = "Error: discard " + user_prog[token_index].getType();
				output_file.push_back(error_message);
				token_index++;
			}
			else if(prod_elem->is_synchronize()){
				/* sync transition, remove first non-terminal */
				stack.pop();
			}
			else{
				//make left most derivation
				vector<Node*> nodes = prod_elem->get_nodes();
				stack.pop();
				for(int index = nodes.size() - 1; index >= 0; index--){
					if(!nodes[index]->is_epsilon()){
						stack.push(nodes[index]);
					}
				}
				output_file.push_back(stack_to_string(stack));
			}
		}
	}

	string derivation_file = "derivation.txt";
	FileWriter::openNewFile(derivation_file);
	for(string line : output_file){
		FileWriter::append(derivation_file, line);
	}
}


string SyntaxAnalyzer::stack_to_string(stack<Node*> tmp){
	string result = "";
	while(!tmp.empty())
	{
		Node* node = tmp.top();
		tmp.pop();
		if(!node->is_dollar() && !node->is_epsilon()){
			result.append(node->get_name());
		}
	}
	return result;
}
