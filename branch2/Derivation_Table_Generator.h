
#ifndef DERIVATION_TABLE_GENERATOR_H_
#define DERIVATION_TABLE_GENERATOR_H_

using namespace std;

class Derivation_Table_Generator {
public:
	Derivation_Table_Generator(vector<Production> rules) ;
	virtual ~Derivation_Table_Generator() ;

private:
	void add_transition (Node non_terminal , Node terminal , Production rule) ;
	Production get_transition (Node non_terminal , Node terminal) ;

private:
	Derivation_Table Table ;

};

#endif /* DERIVATION_TABLE_H_ */
