#include "NFABuilder.h"

NFABuilder::NFABuilder() {
	// TODO Auto-generated constructor stub

}

NFABuilder::~NFABuilder() {
	// TODO Auto-generated destructor stub
}



Machine NFABuilder::build_machine(Rule rule) {
	/* convert rule to postfix. */
	vector<RuleElement> elements = rule.toPostfix();
	/* build machine */
	vector<Machine> stack;
	for(RuleElement element : elements) {
		if(element.isAlpha())
		{
			/* this is a simple character */
			char ch = element.getContent();
			// Epsilon
			if(ch == '#')ch = '\0';
			stack.push_back(Machine(ch)) ;
			continue;
		}

		/* this is an operator */
		if(element.getContent() == '|')
		{
			Machine m1 = stack.back();
			stack.pop_back();
			Machine m2 = stack.back();
			stack.pop_back();
			stack.push_back(OrOperator::apply(m1,m2));
		}
		// dot product will be represented by $ as . can be decimal point
		else if(element.getContent() == '$')
		{
			Machine m1 = stack.back();
			stack.pop_back() ;
			Machine m2 = stack.back();
			stack.pop_back() ;
			stack.push_back(AndOperator::apply(m1,m2)) ;
		}
		else if(element.getContent() == '*')
		{
			Machine m1 = stack.back();
			stack.pop_back() ;
			stack.push_back(KleeneClosureOperator::apply(m1)) ;
		}
		else if(element.getContent() == '+')
		{
			Machine m1 = stack.back();
			stack.pop_back();
			stack.push_back(PositiveClosureOperator::apply(m1)) ;
		}

	}

	stack[0].get_end().set_acceptance(true);
	stack[0].get_end().set_matched_rule(rule);
	return stack[0];
}
