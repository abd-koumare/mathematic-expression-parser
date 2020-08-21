//
// Created by abou on 20/10/19.
//

#include "Expression.h"
#include "Stack.h"
#include "global_const.h"
#include "Operator.h"
#include <stack>
#include <cmath>

#ifndef EXPRESSION_PARSER_PARSER_H
#define EXPRESSION_PARSER_PARSER_H


bool is_operator_or_function_or_delimiter(char);
double calculate(double, char);
double calculate(double, double, char);


Expression infixExpressionToPostfixExpression(Expression &infixExpression)
{

    std::string thePostfixString;
    Stack operatorStack;

    for(size_t i = 0; i < infixExpression.size(); i++) {

        if(infixExpression.at(i).isOperand() || infixExpression.at(i).isFloatingPoint())
            thePostfixString += infixExpression.getCurrentChar();

        else if(infixExpression.at(i).isOperator()) {
            if(!is_operator_or_function_or_delimiter(thePostfixString[thePostfixString.size() - 1]))
                thePostfixString += (char)DELIMITERCHAR;

            while(!operatorStack.isEmpty() && operatorStack.topHasHigherPrecedenceThan(Operator(infixExpression.getCurrentChar()))) {

                thePostfixString += operatorStack.top().getItsChar();
                operatorStack.pop();
            }
            operatorStack.push(infixExpression.getOperator());
        }

        else if(infixExpression.at(i).isLeftParenthesis())
            operatorStack.push(infixExpression.getOperator());

        else if(infixExpression.at(i).isRightParenthesis()) {

            if(!is_operator_or_function_or_delimiter(thePostfixString[thePostfixString.size() - 1]))
                thePostfixString += (char) DELIMITERCHAR;

            while(!operatorStack.isEmpty() && operatorStack.top().getItsChar() != LEFT_PARENTHESIS) {
                thePostfixString += operatorStack.top().getItsChar();
                operatorStack.pop();
            }
            operatorStack.pop();
        }

        //ignore all unknown character
    }

    if(!is_operator_or_function_or_delimiter(thePostfixString[thePostfixString.size() - 1]))
        thePostfixString += (char)DELIMITERCHAR;

    while(!operatorStack.isEmpty()) {

        thePostfixString += operatorStack.top().getItsChar();
        operatorStack.pop();
    }

    return Expression(thePostfixString);
}




double evaluate_postfix_expression(Expression &postfixExpression) {

    std::stack<double> _stack;
    double currentValue = 0;
    unsigned int digitCounter = 0, floatingPointPosition = 0;

    for(size_t i = 0; i < postfixExpression.size(); i++)
    {
        if(postfixExpression.at(i).isOperand()) {
            currentValue = currentValue * 10 + postfixExpression.getOperandValue();
            ++digitCounter;
        }
        else if(postfixExpression.at(i).isFloatingPoint())
            floatingPointPosition = digitCounter;

        else if(postfixExpression.at(i).isDelimiter()) {
            if(floatingPointPosition == 0)
                floatingPointPosition = digitCounter;
            double value = currentValue / pow(10, (digitCounter - floatingPointPosition));
            _stack.push(value);

            floatingPointPosition = 0;
            digitCounter = 0;
            currentValue = 0;
        }
        else if(postfixExpression.at(i).isOperator() && !postfixExpression.isMathematicalFunction()) {
            double secondValue = _stack.top();
            _stack.pop();
            double firstValue = _stack.top();
            _stack.pop();

            double currentResult = calculate(firstValue, secondValue, postfixExpression.getCurrentChar());
            _stack.push(currentResult);
        }
        else if(postfixExpression.at(i).isMathematicalFunction()) {
            double value = _stack.top();
            _stack.pop();

            double currentResult = calculate(value, postfixExpression.getCurrentChar());
            _stack.push(currentResult);
        }

    }

    return _stack.top();

}

double evaluate_string(std::string &expression) {
    Expression infixExpression(expression);
    Expression postfixExpression = infixExpressionToPostfixExpression(infixExpression);
    return evaluate_postfix_expression(postfixExpression);
}


bool is_operator_or_function_or_delimiter(const char character) {
    switch (character) {
        case ADDITION_OPERATOR:
        case SUBSTRACTION_OPERATOR:
        case DIVISION_OPERATOR:
        case MULTIPLICATION_OPERATOR:
        case LOG_FUNCTION:
        case COSINUS_FUNCTION:
        case SINUS_FUNCTION:
        case LN_FUNCTION:
        case DELIMITERCHAR:
            return true;
        default:
            return false;
    }
}


double calculate(double fValue, double sValue, char op) {

    switch(op) {

        case ADDITION_OPERATOR:
            return fValue + sValue;
        case SUBSTRACTION_OPERATOR:
            return fValue - sValue;
        case MULTIPLICATION_OPERATOR:
            return fValue * sValue;
        case DIVISION_OPERATOR:
            return fValue / sValue; // todo:  throw 0 division error
        case EXPONENTIATION_OPERATOR:
            return  pow(fValue, sValue);
        default:
            return 0;
    }
}

double calculate(double value, char func) {

    switch(func) {

        case SINUS_FUNCTION:
            return sin(value);
        case COSINUS_FUNCTION:
            return cos(value);
        case TANGENT_FUNCTION:
            return tan(value);
        case LN_FUNCTION:
            return log(value);
        case LOG_FUNCTION:
            return log10(value);
        default:
            return 0;
    }
}


#endif //EXPRESSION_PARSER_PARSER_H
