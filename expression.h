//
// Created by Admin on 4/29/2021.
//
#pragma once

#include <cmath>
#include "funcs.h"

class expression {
public:
    expression(const std::string &str) ;
    double Calc_value(std::vector<std::vector<expression>> &values, const std::vector<std::string> &names,
                      const std::vector<int> numbers) ;
    bool Is_calc() ;
    double GetValue() ;

private:

    char op;
    std::string arg1, arg2;
    double value=0;
    bool is_calculated = false;
};
