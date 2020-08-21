//
// Created by abou on 20/10/19.
//

#include <stack>
#include "Operator.h"


#ifndef EXPRESSION_PARSER_STACK_H
#define EXPRESSION_PARSER_STACK_H


class Stack {
public:

    bool isEmpty() const;

    Operator top() const;

    void pop();

    bool topHasHigherPrecedenceThan(Operator) const;

    void push(Operator);

private:

    std::stack<Operator> stk;
};


bool Stack::isEmpty() const {
    return stk.empty();
}

Operator Stack::top() const {
    return stk.top();
}

void Stack::pop() {
    //if(!stk.empty()) let the  compiler notify the error much more easier to fix
    stk.pop();
}


void Stack::push(const Operator op) {
    stk.push(op);
}


bool Stack::topHasHigherPrecedenceThan(Operator op) const {
    if (op == stk.top() && op.getAssociativity() == 'R')
        return Operator::getPrecedence(stk.top()) > op.getPrecedence();

    //default
    return Operator::getPrecedence(stk.top()) >= op.getPrecedence();
}


#endif //EXPRESSION_PARSER_STACK_H
