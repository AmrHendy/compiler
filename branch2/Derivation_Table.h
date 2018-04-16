
#ifndef DERIVATION_TABLE_H_
#define DERIVATION_TABLE_H_



using namespace std;

class Derivation_Table {
public:
	Derivation_Table();
	virtual ~Derivation_Table();

public:
	void add_transition (Node non_terminal , Node terminal , ProductionElement rule) ;
	ProductionElement get_transition (Node non_terminal , Node terminal) ;

private:
	map<pair<Node,Node>,ProductionElement> Table ;

};

#endif /* DERIVATION_TABLE_H_ */
