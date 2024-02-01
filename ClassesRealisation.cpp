#include <iostream>
#include <string>
#include <vector>

#include "ClassesRealisation.h"

Tag::Tag() {

}

Tag::Tag(std::string value) {
	this->_value = value;
}

std::string Tag::get() {
	return _value;
}



Printer::Printer() {

}

Printer::Printer(Tag context) {
	_context = context;
}

void Printer::print() {
	std::cout << _context.get() << '\n';
}



DivideCondition::DivideCondition() {

}

DivideCondition::DivideCondition(int dividor) {
	_dividor = dividor;
}

bool DivideCondition::isTruthy(int num) {
	return num % _dividor == 0;
}



Strategy::Strategy() {

}

Strategy::Strategy(std::vector<DivideCondition> conditions) {
	_conditions = conditions;
}

bool Strategy::isTruthy(int num) {
	for (auto& x : this->_conditions) {
		if (x.isTruthy(num) == false) return false;
	}

	return true;
}



TagNumRule::TagNumRule() {

}

TagNumRule::TagNumRule(Tag tag, Strategy strat) {
	_tag = tag;
	_strat = strat;
}

bool TagNumRule::isSuccess(int num) {
	return _strat.isTruthy(num);
}

Tag TagNumRule::getTag() {
	return _tag;
}



TagNumRulesCollection::TagNumRulesCollection() {

}

TagNumRulesCollection::TagNumRulesCollection(std::vector<TagNumRule> tags) {
	_tags = tags;
}

Tag TagNumRulesCollection::find(int num, Tag defaultValue) {
	for (auto& x : _tags) {
		if (x.isSuccess(num))
			return x.getTag();
	}

	return defaultValue;
}