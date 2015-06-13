/*
 * main_test.cpp
 *  Created on: May 25, 2015 3:08:05 PM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */
#include "main_test.h"
#include <stdio.h>
#include "../../src/common/my_glog.h"

int main(int argc, char* argv[]) {
    MyGlog my_glog(argv[0]);
	test_multi_thread();
    test_my_glog();
//    my_glog.~MyGlog();
	return 0;
}



