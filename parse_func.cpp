

#include "parse_func.h"


std::vector<std::string> parse_fline(const std::string &line) {
    std::vector<std::string> result;
    std::string tmp;
    if (line.size() > 2) {
        if (line.at(0) != ',') {
            throw std::runtime_error("wrong first line. name doesnt begin with coma");
        } else {
            tmp = line.substr(1, line.size());
        }

        std::istringstream s(tmp);
        std::string field;
        while (getline(s, field, ',')) {
            if (field.find_first_of("0123456789") == std::string::npos) {
                result.push_back(field);
            } else {
                throw std::runtime_error("wrong first line. name contains digit");
            }
        }
    } else {
        throw std::runtime_error("wrong first line. too short");
    }
    return result;
}

std::vector<expression> parse_reg_line(const std::string &line) {
    std::vector<expression> result;
    if (line.size() <= 2) {
        throw std::runtime_error("wrong line. too short. line: "+line);
    }
    if (line.at(0) != ',') {
        throw std::runtime_error("wrong first line. line doesnt begin with coma. line: "+line);
    }
    std::string tmp;
    tmp = line.substr(1, line.size());
    std::istringstream s(tmp);
    std::string field;
    while (getline(s, field, ',')) {
        result.push_back(expression(field));
    }



    return result;
}

int parse_fst_val(std::string &line){
    auto ind=line.find(',');
    if(ind==std::string::npos){
        throw std::runtime_error("wrong line. cant parse num of row. line: "+line);
    }

    int result=stod(line.substr(0,ind));
    line=line.substr(ind,line.size());
    return result;

}