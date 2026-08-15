#ifndef PARSING
#define PARSING

#include"Fraction.h"
#include<vector>

Fraction parserExpression (std::string const expression);

bool isNumber(std::string const word);
Fraction convertStringToFraction(std::string word);

void priorityCalculator(std::vector<char> &operators, std::vector<Fraction> &fractions);



#endif  // PARSING
