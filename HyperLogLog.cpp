//
// Created by BartoszCybulski on 14.04.2023.
//

#include <algorithm>
#include <set>
#include <iostream>
#include "HyperLogLog.h"

int p(std::string s) {
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            return i +1;
        }
    }
    return (int) s.length()+1;
}

double sum(const std::vector<int> &M) {
    double sum = 0.0;
    for (int i: M) {
        sum = sum + pow(2, -1 * i);
    }
    return sum;
}

int zeroRegisters(const std::vector<int> &reg) {
    int count = 0;
    for (int i: reg) {
        if (i == 0) {
            count++;
        }
    }
    return count;
}
double getAm(int m){
    switch (m){
        case 16:
            return 0.673;
        case 32:
            return 0.697;
        case 64:
            return 0.709;
        default:
            return 0.7213/(1 + 1.079/m);
    }
}

int HyperLogLog(const std::vector<std::string> &Mult, int b)
{
    std::string res;

    //Initialization
    const auto m = (long long int) pow(2, b);
    std::vector<int> M(m , 0);
    double A = getAm(m);

    for (const auto& v: Mult) {
        std::string x = v;
        std::string  tobinary =x.substr(0,b);
        int j = std::stoi(tobinary, nullptr, 2);
        std::string w = x.substr(b);
        M[j] = std::max(M[j], p(w));
    }

    double E = A * m * m * 1 / sum(M);
    double Ep = 0;

    //Corrections
    if (E <= 2.5 * (double) m) {
        int V = zeroRegisters(M);
        if (V != 0) {
            Ep = m * log((double)m / (double)V);
        } else {
            Ep = E;
        }
    } else if (E <= 1.0 / 30.0 * pow(2, 32)) {
//        std::cout<< "Second b =  " +  std::to_string(b) + "Mult size =" + std::to_string((Mult.size())) << std::endl;
        Ep = E;
    }else  if(E > 1.0 / 30.0 * pow(2, 32)) {
 //       std::cout<< "Third b =  " +  std::to_string(b) + "Mult size =" + std::to_string((Mult.size())) << std::endl;
        Ep = -1 * pow(2, 32) * log(1 - E / pow(2, 32));
    }

    return (int) round(Ep);
}
