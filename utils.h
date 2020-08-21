//
// Created by abou on 20/10/19.
//

#include "global_const.h"
#include <string>

#ifndef EXPRESSION_PARSER_UTILS_H
#define EXPRESSION_PARSER_UTILS_H


const unsigned int precedence(char);

const char associativity(char);

const unsigned int precedence(const char op) {
    switch (op) {
        case ADDITION_OPERATOR:
        case SUBSTRACTION_OPERATOR:
            return 4;
        case MULTIPLICATION_OPERATOR:
        case DIVISION_OPERATOR:
            return 6;
        case EXPONENTIATION_OPERATOR:
            return 8;
        case SINUS_FUNCTION:
        case TANGENT_FUNCTION:
        case COSINUS_FUNCTION:
            return 10;
        default:
            return 1; //for left parenthesis
    }

}


const char associativity(const char op) {
    switch (op) {
        case ADDITION_OPERATOR:
        case SUBSTRACTION_OPERATOR:
        case MULTIPLICATION_OPERATOR:
            return 'L'; //left associative
        case DIVISION_OPERATOR:
        case EXPONENTIATION_OPERATOR:
        case SINUS_FUNCTION:
        case TANGENT_FUNCTION:
        case COSINUS_FUNCTION:
            return 'R'; // right associative
        default:
            return 'L'; //default associativity
    }

}


#endif //EXPRESSION_PARSER_UTILS_H
