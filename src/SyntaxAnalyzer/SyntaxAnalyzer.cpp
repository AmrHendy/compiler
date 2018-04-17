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
	/* construction stack */
	list<Node*> stack;
	/* get first transtion in table */
	/* ----------- REQUIRED INTERFACE METHOD ----------- */
	string start_nt_name = derivation_table.get_non_terminal_start();
	/* ----------- REQUIRED INTERFACE METHOD ----------- */ 
	ProductionElement* tmp = derivation_table.get_transition(start_nt_name, user_prog[0].getType());
	for(Node* n : tmp->get_nodes())
	{
		stack.push_back(n);
	}
	

	for(Token current_token : user_prog)
	{
		string stack_front_name = stack.front()->get_name();
		string token_name = current_token.getType();

		if(stack.front()->get_type() == Terminal)
		{
			/* match */
			if(token_name.compare(stack_front_name) != 0)
			{
				/* report error */
				return;
			}
			/* remove first production node */
			stack.pop_front();
			continue;

		}
		else /* non-terminal */
		{
			ProductionElement* tmp2 = derivation_table.get_transition(stack_front_name, token_name);
			stack.pop_front();
			vector<Node*> tmp3 = tmp2->get_nodes();
			for(int i = tmp3.size()-1 ; i >= 0; i--)
			{
				stack.push_front(tmp3[i]);
			}
		}
	}
}
