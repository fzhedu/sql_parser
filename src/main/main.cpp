//============================================================================
// Name        : cpp_parser.cpp
// Author      : fzh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "../../src/parser/sql_parser.h"
using namespace std;
int main() {
    Parser* my_parser = new Parser();
    my_parser->GetRawAST()->Print();
    return 0;
}
