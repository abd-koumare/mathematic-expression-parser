#include <iostream>
#include "parser.h"
#include "Expression.h"

int main() {
    Expression ie("s(2.5)");
    Expression pe = infixExpressionToPostfixExpression(ie).getExpression();

    std::cout << pe.getExpression() << std::endl;
}
