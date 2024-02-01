#include <iostream>
#include <string>
#include <vector>

#include "ClassesRealisation.h"

void getDecisions(TagNumRulesCollection& numTags, int N) {
	for (int i = 0; i <= N; i++) {
		Printer(numTags.find(i, Tag(std::to_string(i)))).print();
	}
}

int main(){

	// define tags collection, how many rules; each rule has tag and strategy which has as many conditions as you wish.
	TagNumRulesCollection numTags({ TagNumRule(Tag("FizzBuzz"), Strategy( {DivideCondition(3), DivideCondition(5) })),
									TagNumRule(Tag("Fizz"), Strategy( {DivideCondition(3)} )),
									TagNumRule(Tag("Buzz"), Strategy( {DivideCondition(5)} ))
	});

	int N = 33;
	
	getDecisions(numTags, N);
}
