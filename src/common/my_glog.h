/*
 * my_glog.h
 *  Created on: Jun 12, 2015 11:07:40 PM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#ifndef MY_GLOG_H_
#define MY_GLOG_H_
#include <glog/logging.h>
#include <glog/raw_logging.h>
#include <gflags/gflags.h>
void GlogSignalHandle(const char* data, int size);
class MyGlog {
 public:
    MyGlog(char* program);
    ~MyGlog();
};

#endif /* MY_GLOG_H_ */
