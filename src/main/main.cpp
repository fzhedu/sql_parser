//============================================================================
// Name        : cpp_parser.cpp
// Author      : fzh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>  //NOLINT
#include <string>
#include "../../src/parser/sql_parser.h"

int main() {
    char loopflag = ' ';
    do {
        Parser* my_parser = new Parser();
        my_parser->GetRawAST()->Print();
        delete my_parser;
        std::cout << "want to continue? y or n ?" << std::endl;
        std::cin >> loopflag;
    } while (loopflag == 'y');
    return 0;
}
