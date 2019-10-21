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

const Expression infixExpressionToPostfixExpression(const Expression &exp);

double calculate(double fValue, double sValue, char op);

double caculate(double value, char func);

double eval(Expression &exp);


double calculate(double fValue, double sValue, char op)
{
    switch(op)
    {
        case ADDITION_OPERATOR:
            return fValue + sValue;
        case SUBSTRACTION_OPERATOR:
            return fValue - sValue;
        case MULTIPLICATION_OPERATOR:
            return fValue * sValue;
        case DIVISION_OPERATOR:
            return fValue / sValue; //fix   throw an error missing
        case EXPONENTIATION_OPERATOR:
            return  pow(fValue, sValue);
    }
    return 0;
}

double calculate(double value, char func)
{
    switch(func)
    {
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
    }
    return 0;//appease gcc will always be call with meaningfull func
}



Expression infixExpressionToPostfixExpression(Expression &exp)
{

    std::string thePostfixString;
    Stack operatorStack;


    for(size_t i = 0; i < exp.size(); i++)
    {
        if(exp.at(i).isOperand() || exp.at(i).isFloatingPoint())
            thePostfixString += exp.getCurrentChar();

        else if(exp.at(i).isOperator())
        {

            thePostfixString += DELIMITERCHAR;
            while(!operatorStack.isEmpty() && operatorStack.topHasHigherPrecedenceThan(Operator(exp.getCurrentChar())))
            {
                thePostfixString += operatorStack.top().getItsChar();
                operatorStack.pop();
            }
            operatorStack.push(exp.getOperator());
        }

        else if(exp.at(i).isLeftParenthesis())
            operatorStack.push(exp.getOperator());

        else if(exp.at(i).isRightParenthesis())
        {
            while(!operatorStack.isEmpty() && operatorStack.top().getItsChar() != LEFT_PARENTHESIS)
            {
                thePostfixString += operatorStack.top().getItsChar();
                operatorStack.pop();
            }
            operatorStack.pop();
        }

        //ignore all unknown charater
    }

    while(!operatorStack.isEmpty())
    {
        thePostfixString += operatorStack.top().getItsChar();
        operatorStack.pop();
    }


    return Expression(thePostfixString);
}




double eval(Expression &exp)
{
    std::stack<double> _stack;
    double currentValue = 0;
    unsigned int digitCounter = 0, floatingPointPosition = 0;

    for(size_t i = 0; i < exp.size(); i++)
    {
        if(exp.at(i).isOperand())
        {
            currentValue = currentValue * 10 + exp.getOperandValue();
            ++digitCounter;
        }
        else if(exp.at(i).isFloatingPoint())
        {
            floatingPointPosition = digitCounter;
        }

    }
}

#endif //EXPRESSION_PARSER_PARSER_H
