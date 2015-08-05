/*
 * my_glog.h
 *  Created on: Jun 12, 2015 11:07:40 PM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#ifndef SRC_COMMON_LOGGING_H_
#define SRC_COMMON_LOGGING_H_
#define NDEBUG  // switch to no_debug mode

#include <glog/logging.h>
#include <glog/raw_logging.h>
#include <gflags/gflags.h>

#define LOG_INFO LOG(INFO)
#define LOG_WARNING LOG(WARNING)
#define LOG_ERROR LOG(ERROR)

void GlogSignalHandle(const char* data, int size);
class Logging {
 public:
    explicit Logging(char* program);
    ~Logging();
};

#endif /* SRC_COMMON_LOGGING_H_ */
