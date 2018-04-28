#include "../../../header/SyntaxAnalyzer/GrammerElimination/LeftRecursionElimination.h"

LeftRecursionElimination::LeftRecursionElimination(vector<Production*> rules) {
	start_non_terminal = rules[0]->get_LHS_name();
	this->rules = rules;
	Elimination_controller (rules);
}

LeftRecursionElimination::~LeftRecursionElimination() {
	// TODO Auto-generated destructor stub
}

void LeftRecursionElimination::Elimination_controller(vector <Production*> rules){
    string non_terminal;
    vector<ProductionElement*> RHS;
    vector<int> matched_indexes;
    vector<Production*> modified_rules;
    for (int i=0;i<rules.size();i++){
        non_terminal=rules[i]->get_LHS_name();

        RHS=rules[i]->get_RHS_elements();
        matched_indexes = get_matched_indexes(non_terminal,RHS);

        if (!matched_indexes.empty()){
        	modified_rules = elimination(non_terminal,RHS,matched_indexes);
            for (int j=0;j<modified_rules.size();j++){
                result_rules.push_back(modified_rules[j]);
            }
        }
        else{
        	Production* temp_rule = new Production(non_terminal);
        	temp_rule->add_element(RHS);
        	result_rules.push_back(temp_rule);
        }
    }
    reorder();
}

// get indexes of elements which have left recursion
vector<int> LeftRecursionElimination::get_matched_indexes(string non_terminal,vector<ProductionElement*>& RHS){
    vector <Node*> nodes;
    vector <int> matched_indexes;// elements which have left recursion
    ProductionElement* temp;
    int index;
     for (int i=0;i<RHS.size();i++){
        nodes=RHS[i]->get_nodes();
        if(!nodes[0]->get_type()==Terminal){
            if (nodes[0]->get_name()==non_terminal){
                matched_indexes.push_back(i);
            }else{
                // -1 means no left recursion
                index=check_LR(nodes[0]->get_name());
                if (index!=-1){
                    temp=RHS[i];
                    RHS.erase(RHS.begin()+i);
                    i--;
                    temp->remove_first_node();
                    RHS = modify_RHS(RHS,temp,index);  // append the other no3des in this element to the exist rule
                }
            }
        }
     }
     return matched_indexes;
}

vector<ProductionElement*> LeftRecursionElimination::modify_RHS(vector<ProductionElement*>RHS,ProductionElement* temp,int index){
    Node* append_node;
    vector <Node*> nodes=temp->get_nodes();

    vector<ProductionElement*> elements;
    for(ProductionElement* elem : result_rules[index]->get_RHS_elements()){
    	ProductionElement* temp_elem = new ProductionElement();
    	for(Node* nodee : elem->get_nodes()){
    		temp_elem->add_node(new Node(nodee->get_name(), nodee->get_type()));
    	}
    	elements.push_back(temp_elem);
    }


    for (int i=0;i<elements.size();i++){
        for (int j=0;j<nodes.size();j++){
            elements[i]->add_node(new Node(nodes[j]->get_name(), nodes[j]->get_type()));
        }
        RHS.push_back(elements[i]);
    }
    return RHS;
}

int LeftRecursionElimination::check_LR(string non_terminal){
    for (int i=0;i<result_rules.size();i++){
        if (result_rules[i]->get_LHS_name()==non_terminal){
            return i;
        }
    }
    return -1;
}
      // eliminate left recursion and produce new rules with out left recursion;
vector<Production*> LeftRecursionElimination::elimination(string non_terminal,vector<ProductionElement*> elements,vector<int> matched_indexes){
    vector <Production*> modified_rules;
    string non_terminal2 = get_correct_name(non_terminal);
    Production* rule1 =new Production(non_terminal);
    Production* rule2 =new Production(non_terminal2);
    Node* temp=new Node(non_terminal2,NonTerminal);
    Node* temp2=new Node("'\\L'",Terminal);
    bool exist;
    ProductionElement* epsilon = new ProductionElement();

    for (int i=0;i<elements.size();i++){
        exist=false;
        for (int j=0;j<matched_indexes.size();j++){
            if (i==matched_indexes[j]){
                exist=true;
            }
        }
        if (exist){
            elements[i]->remove_first_node();
            if (elements[i]->get_nodes().empty()){
                elements[i]->add_node(temp2);
            }
            elements[i]->add_node(temp);
            rule2->add_element(elements[i]);
        }else{
            elements[i]->add_node(temp);
            rule1->add_element(elements[i]);
        }
    }

	epsilon->add_node(temp2);
	rule2->add_element(epsilon);
	if (rule1->get_RHS_elements().empty()){
		epsilon->add_node(temp);
		rule1->add_element(epsilon);
	}
	modified_rules.push_back(rule1);
	modified_rules.push_back(rule2);
	return modified_rules;
}

vector<Production*> LeftRecursionElimination::get_eliminated_rules(){
    return result_rules;
}

string LeftRecursionElimination::get_correct_name(string non_terimnal){
	string result=non_terimnal,temp;
	bool derived;
	for (int i=0;i<result_rules.size();i++){
		derived=false;
		temp=result_rules[i]->get_LHS_name();
		if (result.size()<=temp.size()&&result==temp.substr(0,result.size())){
			derived=true;
			for(int j=result.size();j<temp.size();j++){
				if (temp[j]!='\''){
					derived=false;
					break;
				}
			}
		}
		if (derived)
			result=temp;
	}
	result += "'";
	string prev_result = result;

	for (int i=0;i<rules.size();i++){
		derived=false;
		temp = rules[i]->get_LHS_name();
		if (result.size()<=temp.size()&&result==temp.substr(0,result.size())){
			derived=true;
			for(int j=result.size();j<temp.size();j++){
				if (temp[j]!='\''){
					derived=false;
					break;
				}
			}
		}
		if (derived)
			result=temp;
	}
	if(result != prev_result){
		result += "'";
	}
	return result;
}

void LeftRecursionElimination::reorder(){
	vector<Production*> ordered;
	for(Production* prod : result_rules){
		if(prod->get_LHS_name() == start_non_terminal){
			ordered.push_back(prod);
			break;
		}
	}

	for(Production* prod : result_rules){
		if(prod->get_LHS_name() != start_non_terminal){
			ordered.push_back(prod);
		}
	}
	result_rules = ordered;
}
