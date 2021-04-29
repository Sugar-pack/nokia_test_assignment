//
// Created by Admin on 4/29/2021.
//

#pragma once

#include <string>
#include <algorithm>
#include <stdexcept>
#include <vector>

bool is_digits(const std::string &str) ;


size_t find_indx_name(const size_t &pos_of_num, std::string arg, const std::vector<std::string> &names) ;
size_t find_indx_num(const size_t &pos_of_num, std::string arg, const std::vector<int> &numbers) ;
double calcval(const double &fst, const double &snd, const char &op) ;




