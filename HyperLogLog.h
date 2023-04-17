//
// Created by BartoszCybulski on 14.04.2023.
//

#ifndef HYPERLOGLOG_HYPERLOGLOG_H
#define HYPERLOGLOG_HYPERLOGLOG_H

#include <string>
#include <vector>
#include <cmath>


enum hashType {
    MD5, SHA1,  SHA256, SHA512
};

int HyperLogLog(const std::vector<std::string> &Mult, int b);

#endif //HYPERLOGLOG_HYPERLOGLOG_H
