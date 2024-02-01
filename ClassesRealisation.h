#include <iostream>
#include <string>
#include <vector>

#ifndef TAG_H
#define TAG_H

class Tag {
private:
	std::string _value;
public:
	Tag();

	Tag(std::string value);

	std::string get();
};

#endif // !TAG_H


#ifndef PRINTER_H
#define PRINTER_H

class Printer {
private:
	Tag _context;
public:
	Printer();

	Printer(Tag context);

	void print();
};

#endif // !PRINTER_H


#ifndef DIVIDECONDITION_H
#define	DIVIDECONDITION_H

class DivideCondition {
private:
	int _dividor;
public:
	DivideCondition();

	DivideCondition(int dividor);

	bool isTruthy(int num);
};

#endif // !DivideCondition


#ifndef STRATEGY_H
#define STRATEGY_H
// This is "AND" strategy - if 1 condition is not satisfied -> false
class Strategy { 
private:
	std::vector<DivideCondition> _conditions;
public:
	Strategy();

	Strategy(std::vector<DivideCondition> conditions);

	bool isTruthy(int num);
};

#endif // !STRATEGY_H


#ifndef TAG_NUM_RULE_H
#define TAG_NUM_RULE_H

class TagNumRule {
private:
	Tag _tag;
	Strategy _strat;
public:
	TagNumRule();

	TagNumRule(Tag tag, Strategy strat);

	bool isSuccess(int num);

	Tag getTag();
};

#endif // !TAG_NUM_RULE_H


#ifndef TAGNUMRULESCOLLECTION_H
#define TAGNUMRULESCOLLECTION_H

class TagNumRulesCollection {
private:
	std::vector<TagNumRule> _tags;
public:
	TagNumRulesCollection();

	TagNumRulesCollection(std::vector<TagNumRule> tags);

	Tag find(int num, Tag defaultValue);
};

#endif // !TAGNUMRULESCOLLECTION_H
