//
// Created by abou on 20/10/19.
//


#ifndef EXPRESSION_PARSER_OPERATOR_H
#define EXPRESSION_PARSER_OPERATOR_H

#include "utils.h"
#include "Operator.h"

class Operator {
public:
    Operator(const char);

    unsigned int getPrecedence();

    char getAssociativity();

    void setOperator(const char);

    char getItsChar() const;

    bool operator==(const Operator &) const;

    static unsigned int getPrecedence(const Operator &op) {
        return precedence(op.getItsChar());
    }

    static char getAssociativity(const Operator &op) {
        return associativity(op.getItsChar());
    }

private:

    unsigned int itsPrecedence;
    char itsAssociativity;
    char itsChar;


};


Operator::Operator(const char theOperator) {
    itsPrecedence = precedence(theOperator);
    itsAssociativity = associativity(theOperator);
    itsChar = theOperator;
}

unsigned int Operator::getPrecedence() {
    return itsPrecedence;
}

char Operator::getAssociativity() {
    return itsAssociativity;
}

void Operator::setOperator(const char theOperator) {
    itsPrecedence = precedence(theOperator);
    itsAssociativity = associativity(theOperator);
    itsChar = theOperator;
}

char Operator::getItsChar() const {
    return itsChar;
}

bool Operator::operator==(const Operator &rhs) const {
    return (*this).getItsChar() == rhs.getItsChar();
}


#endif //EXPRESSION_PARSER_OPERATOR_H
