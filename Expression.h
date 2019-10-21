//
// Created by abou on 20/10/19.
//
#include <string>
#include "utils.h"
#include "global_const.h"
#include "Operator.h"
#ifndef EXPRESSION_PARSER_EXPRESSION_H
#define EXPRESSION_PARSER_EXPRESSION_H


class Expression
{


public:

    Expression(const std::string theExpression)
            :cursor(0), startingIndex(0), endingIndex(theExpression.size() -1)
    {
        if(theExpression.at(0) == '-')
            expression = '0' + theExpression;
        else
            expression = theExpression;
    }



    //checkers

    bool isOperand() const;
    bool isOperator() const;
    bool isLeftParenthesis() const;
    bool isRightParenthesis() const;
    bool isMathematicalFunction() const;
    bool isFloatingPoint() const;
    bool isDelimiter() const;

    //getters
    std::string getExpression() const;
    unsigned int getOperatorPrecedence() const;
    char getOperatorAssociativity() const;
    unsigned int getCursor() const;
    unsigned int getOperandValue() const;

    char getCurrentChar() const;
    Operator getOperator() const;
    unsigned int size() const;


    Expression& next();
    Expression& back();
    Expression& operator[](const unsigned short);
    Expression& at(const unsigned short);


    //setters or modifiers
    void setExpression(const std::string);



private:

    std::string expression;
    unsigned int cursor;
    const unsigned int startingIndex;
    const unsigned int endingIndex;
};



Expression& Expression::next()
{
    if(cursor < endingIndex)
        ++cursor;

    return (*this);
}


Expression& Expression::back()
{
    if(cursor > startingIndex)
        --cursor;

    return (*this);
}



//checkers

bool Expression::isOperand() const
{
    return expression.at(cursor) >= '0' && expression.at(cursor) <= '9';
}



bool Expression::isOperator() const
{
    switch(expression.at(cursor))
    {
        case ADDITION_OPERATOR:
        case SUBSTRACTION_OPERATOR:
        case MULTIPLICATION_OPERATOR:
        case DIVISION_OPERATOR:
        case EXPONENTIATION_OPERATOR:
        case SINUS_FUNCTION:
        case TANGENT_FUNCTION:
        case COSINUS_FUNCTION:
            return true;

    }
    return false; //instead of double default
}

//getters
std::string Expression::getExpression() const
{
    return expression;
}


unsigned int Expression::getOperatorPrecedence() const

{
    return precedence(expression.at(cursor));
}


char Expression::getOperatorAssociativity() const
{
    return associativity(expression.at(cursor));
}


unsigned int Expression::getCursor() const
{
    return cursor;
}


unsigned int Expression::getOperandValue() const
{
    return expression.at(cursor) - '0';
}


char Expression::getCurrentChar() const
{
    return expression.at(cursor);
}



Operator Expression::getOperator() const
{
    return Operator(expression.at(cursor));
}

void Expression::setExpression(std::string theExpression)
{
    if(theExpression.at(0) == '-')
        expression = '0' + theExpression;
    else
        expression = theExpression;

    cursor = 0;
}

Expression& Expression::operator[](const unsigned short offset)
{
    if(offset <= endingIndex)
        cursor = offset;
    return (*this);
}

unsigned int Expression::size() const
{
    return expression.size();
}

Expression& Expression::at(const unsigned short offset)
{

    if(offset <= endingIndex)
        cursor = offset;
    return (*this);
}


bool Expression::isLeftParenthesis() const
{
    return expression.at(cursor) == LEFT_PARENTHESIS;
}


bool Expression::isRightParenthesis() const
{
    return expression.at(cursor) == RIGHT_PARENTHESIS;
}


bool Expression::isMathematicalFunction() const
{
    switch(expression.at(getCursor()))
    {
        case COSINUS_FUNCTION:
        case SINUS_FUNCTION:
        case TANGENT_FUNCTION:
            return true;
    }
    return false;
}


bool Expression::isFloatingPoint() const
{
    return expression.at(cursor) == FLOATING_POINT;
}


bool Expression::isDelimiter() const
{
    return expression.at(cursor) == DELIMITERCHAR;
}

#endif //EXPRESSION_PARSER_EXPRESSION_H
