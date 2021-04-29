//
// Created by Admin on 4/29/2021.
//

#include "expression.h"

    expression::expression(const std::string &str) {
        if (is_digits(str)) {
            value = stod(str);
            is_calculated = true;
        } else {
            if (str.size() < 4) { // min looks like '=1+1'
                throw std::runtime_error("wrong expression. length is too low");
            };
            if (str.at(0) != '=') {
                throw std::runtime_error("wrong expression. does not start with an = sign ");
            };

            size_t pos_of_op = std::string::npos;
            std::vector<char> possible_op = {'+', '-', '*', '/'};
            int i = 0;
            while (i < possible_op.size() and pos_of_op == std::string::npos) {
                char tmp_op = possible_op[i];
                pos_of_op = str.find(tmp_op);
                if (pos_of_op == str.size() - 1 or pos_of_op == 1) {
                    throw std::runtime_error("wrong expression. arg is missing ");
                }
                if (pos_of_op != std::string::npos) {
                    arg1 = str.substr(1, pos_of_op - 1);
                    //std::cout<< arg1 << std::endl;
                    arg2 = str.substr(pos_of_op + 1, str.size() - pos_of_op);
                    //std::cout<< arg2 << std::endl;
                    op = tmp_op;
                    //std::cout<< op << std::endl;
                }
                ++i;
            }
            if (pos_of_op == std::string::npos) {
                throw std::runtime_error("wrong expression. can't find op");
            }

        }
    }

    double expression::Calc_value(std::vector<std::vector<expression>> &values, const std::vector<std::string> &names,
                                  const std::vector<int> numbers) {
        if (is_calculated) {
            return value;
        } else {
            double tmp1, tmp2;

            size_t pos_of_num1 = arg1.find_first_of("0123456789");
            if (pos_of_num1 == std::string::npos) {
                throw std::runtime_error("wrong expression. arg doesnt contain digit");
            }

            if (pos_of_num1 == 0) {
                if (is_digits(arg1)) {
                    tmp1 = stod(arg1);
                    //std::cout << "tmp1= "<< tmp1 << std::endl;
                } else {
                    throw std::runtime_error("wrong arg. arg begins from digit but arg isn't number");
                }

            } else {
                size_t indx_name1 = find_indx_name(pos_of_num1, arg1, names);
                size_t indx_num1 = find_indx_num(pos_of_num1, arg1, numbers);
                if (values[indx_num1][indx_name1].Is_calc()) {
                    tmp1 = values[indx_num1][indx_name1].GetValue();
                } else {
                    throw std::runtime_error("wrong arg. cant calc value");
                }
            }

            size_t pos_of_num2 = arg2.find_first_of("0123456789");

            if (pos_of_num2 == std::string::npos) {
                throw std::runtime_error("wrong expression. arg doesnt contain digit");
            }
            if (pos_of_num2 == 0) {
                if (is_digits(arg2)) {
                    tmp2 = stod(arg2);
                    //std::cout << "tmp2= "<< tmp1 << std::endl;
                } else {
                    throw std::runtime_error("wrong arg. arg begins from digit but arg isn't number");
                }

            } else {
                size_t indx_name2 = find_indx_name(pos_of_num2, arg2, names);
                size_t indx_num2 = find_indx_num(pos_of_num2, arg2, numbers);
                if (values[indx_num2][indx_name2].Is_calc()) {
                    tmp2 = values[indx_num2][indx_name2].GetValue();
                } else {
                    throw std::runtime_error("wrong arg. cant calc value");
                }

            }
            value=calcval(tmp1, tmp2, op);
            is_calculated = true;
            return GetValue();
        }
}


bool expression::Is_calc() {
        return is_calculated;
    }

double expression::GetValue() {
        if(Is_calc()){
            return value;
        }
        else{
            return std::nan("");
        }
    }



