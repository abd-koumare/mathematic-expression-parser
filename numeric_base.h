//
// Created by abou on 20/10/19.
//

#include <stack>
#include <vector>
#include <cmath>
#ifndef EXPRESSION_PARSER_NUMERIC_BASE_H
#define EXPRESSION_PARSER_NUMERIC_BASE_H


enum
{
    BASE_2 = 2,
    BASE_8 = 8,
    BASE_16 = 16
};


std::stack<short> decimalTo(unsigned int BASE_N , unsigned int value)
{

    std::stack<short> stk;
    while(value != 0)
    {
        stk.push(value % BASE_N);
        value /= BASE_N;
    }

    return stk;
}


double BASE_N_ToDecimal(unsigned int BASE_N, std::vector<char> value)
{

    unsigned int j = 0;
    int size = value.size();
    double decimalValue = 0;

    for(int i = (size - 1); i >= 0; i--)
    {
        char currentChar = value[i];
        if(currentChar >= 'A' && currentChar <= 'F')
            decimalValue += (currentChar - 55) * pow(BASE_N, j);
        else
            decimalValue += (currentChar - '0') * pow(BASE_N, j);
        ++j;
    }
    return decimalValue;
}



std::vector<char> stringify(std::stack<short> &stk)
{

    std::vector<char> v;
    while(!stk.empty())
    {
        char currentChar;
        if(stk.top() >= 10 && stk.top() <= 15)
            currentChar = stk.top() + ('A' - 10);
        else
            currentChar = '0' + stk.top();

        v.push_back(currentChar);
        stk.pop();
    }

    return v;
}

#endif //EXPRESSION_PARSER_NUMERIC_BASE_H
