//
// Created by Admin on 4/29/2021.
//

#include "funcs.h"
bool is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}


size_t find_indx_name(const size_t &pos_of_num, std::string arg, const std::vector<std::string> &names) {
    std::string name1 = arg.substr(0, pos_of_num);
    auto it_name1 = std::find(names.begin(), names.end(), name1);
    size_t indx_name1 = std::distance(names.begin(), it_name1);
    if (indx_name1 == names.size()) {
        throw std::runtime_error("wrong arg. can't find name of column");
    }
    //std::cout << indx_name1 << std::endl;
    return indx_name1;
}

size_t find_indx_num(const size_t &pos_of_num, std::string arg, const std::vector<int> &numbers) {

    std::string snum1 = arg.substr(pos_of_num, arg.size() - 1);
    if (!is_digits(snum1)) {
        throw std::runtime_error("wrong arg. number of row is missing");
    }
    double number1 = stod(snum1);
    auto it_num1 = std::find(numbers.begin(), numbers.end(), number1);
    size_t indx_num1 = std::distance(numbers.begin(), it_num1);
    if (indx_num1 == numbers.size()) {
        throw std::runtime_error("wrong arg. can't find number of row");
    }
    //std::cout << indx_num1 << std::endl;
    return indx_num1;
}

double calcval(const double &fst, const double &snd, const char &op) {
    if (op == '/' and snd == 0) {
        throw std::runtime_error("div by zero");
    } else {
        if (op == '+') {
            return fst + snd;
        } else if (op == '-') {
            return fst - snd;
        } else if (op == '*') {
            return fst * snd;
        } else if (op == '/') {
            return fst / snd;
        } else {
            throw std::runtime_error("calc. wrong op");
        }
    }
}

