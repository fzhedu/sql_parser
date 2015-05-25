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
#include <stdio.h>
using namespace std;
int main() {
    int flag = 1;
    while(flag) {
        Parser* my_parser = new Parser();
        my_parser->GetRawAST()->Print();
        delete my_parser;
        printf("continue 1 or not 0!\n");
        scanf("%d",&flag);
    }
	return 0;
}
