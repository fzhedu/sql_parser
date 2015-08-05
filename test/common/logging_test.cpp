/*
 * my_glog_test.cpp
 *  Created on: Jun 13, 2015 9:37:21 AM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */
#include <../../src/common/logging.h>
#include <stdio.h>
#include <iostream>
void test_my_glog() {
  std::cout << "----test my glog begin--------------" << std::endl;
//    google::InitGoogleLogging(argv[0]);
//    google::ParseCommandLineFlags(&argc, &argv, true);
//    FLAGS_log_dir = "./log";
//    FLAGS_logtostderr=1;
//    FLAGS_colorlogtostderr=true;
  LOG(INFO)<< "info: hello world!";
  LOG(WARNING)<< "warning: hello world!";
  LOG(ERROR)<< "error: hello world!";
//    LOG(FATAL) << "fatal: hello world!";
  VLOG(0) << "vlog0: hello world!";
  VLOG(1) << "vlog1: hello world!";
  VLOG(2) << "vlog2: hello world!";
  VLOG(3) << "vlog3: hello world!";
  DLOG(INFO)<< "DLOG: hello world!";

  for (int i = 1; i <= 100; i++) {
    LOG_IF(INFO, i ==100) << "LOG_IF(INFO,i==100)  google::COUNTER="
                        << google::COUNTER << "  i=" << i;
    LOG_EVERY_N(INFO, 10) << "LOG_EVERY_N(INFO,10)  google::COUNTER="
                          << google::COUNTER << "  i=" << i;
    LOG_IF_EVERY_N(WARNING, (i > 50), 10)
        << "LOG_IF_EVERY_N(INFO,(i>50),10)  google::COUNTER=" << google::COUNTER
        << "  i=" << i;
    LOG_FIRST_N(ERROR, 5)
    << "LOG_FIRST_N(INFO,5)  google::COUNTER=" << google::COUNTER << "  i="
    << i;
  }
//    CHECK_NE(2, 2) << ": The world must be ending!";
//    google::ShutDownCommandLineFlags();
//    google::ShutdownGoogleLogging();
  std::cout << "---------------------test my glog end---------------------"
            << std::endl;
}

