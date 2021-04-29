#include <iostream>
#include <exception>
#include <sstream>
#include "csv_table.h"




int main(int argc, char *argv[]) {
    try {
        if(argc!=2){
            throw std::runtime_error("wrong args");
        }
        csv_table test(argv[1]);
        test.Print();

    } catch (std::exception &e) {
        std::cerr << "Error. Hint: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception caught" << std::endl;
    }

    return 0;
}
