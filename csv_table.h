//
// Created by Admin on 4/29/2021.
//

#pragma once

#include <fstream>
#include <iostream>
#include "parse_func.h"
#include "expression.h"
class csv_table {
public:
    csv_table(const std::string &filename) {

        std::ifstream csvFile(filename);
        if(!csvFile){
            throw std::runtime_error("cant open file with name "+filename);
        }
        std::string fline;
        if (std::getline(csvFile, fline)) {
            Name_of_column = parse_fline(fline);
        } else {
            throw std::runtime_error("wrong data. cant read first line");
        }
        std::string line;
        while (std::getline(csvFile, line)) {
            auto tmpline=line;
            int val = parse_fst_val(tmpline);
            Number_of_row.push_back(val);
            auto exprs= parse_reg_line(tmpline);
            if (exprs.size()!=Name_of_column.size()){
                throw std::runtime_error("wrong line. number of col isnt correct "+line);
            }
            data.push_back(exprs);
        }

        Calc_Value();
    }

    void Print(){



        for(auto i:Name_of_column){
            std::cout<< ','<< i ;
        }
        std::cout<<std::endl;

        for(auto i=0;i<data.size();++i){
            std::cout<<Number_of_row[i];
            for(auto j=0;j<data[i].size();++j){
                std::cout<<','<<data[i][j].GetValue();
            }
            std::cout<<std::endl;
        }

    }

private:
    void Calc_Value(){
        for(auto i=0;i<data.size();++i){
            for(auto j=0;j<data[i].size();++j){
                data[i][j].Calc_value(data,Name_of_column,Number_of_row);
            }
        }
    }

    std::vector<std::string> Name_of_column;
    std::vector<int> Number_of_row;
    std::vector<std::vector<expression>> data;

};
