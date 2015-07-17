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
#include <stdio.h>
#include <glog/logging.h>
#include <gflags/gflags.h>

#include "../common/logging.h"
int main(int argc, char* argv[]) {
    Logging my_glog(argv[0]);
    int flag = 1;
    while (flag) {
        Parser* my_parser = new Parser();
        if (my_parser->GetRawAST() != NULL )
          my_parser->GetRawAST()->Print();
        delete my_parser;
        printf("continue 1 or not 0!\n");
        scanf("%d", &flag);
    }

    return 0;
}
