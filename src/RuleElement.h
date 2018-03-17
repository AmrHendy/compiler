/*
 * RuleElement.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef RULEELEMENT_H_
#define RULEELEMENT_H_

enum Type {alpha, operation};


class RuleElement {
public:
	RuleElement(char ch, Type type);
	virtual ~RuleElement();
	char content;
	Type type;
};

#endif /* RULEELEMENT_H_ */
