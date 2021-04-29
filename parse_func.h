//
// Created by Admin on 4/29/2021.
//
#pragma once

#include <sstream>
#include "expression.h"

std::vector<std::string> parse_fline(const std::string &line);

std::vector<expression> parse_reg_line(const std::string &line);

int parse_fst_val(std::string &line);