#include "util.h"
#include <iostream>

std::string& trim(std::string &s) {
    if (s.empty()) {
        return s;  
    }

    s.erase(0,s.find_first_not_of(" "));  
    s.erase(s.find_last_not_of(" ") + 1);  
    return s;  
}

std::string numToBinStr(unsigned int num, int bit) {
    std::string zero = "0", one = "1", rst;
    while (num || bit) {
        if (num & 1) {
            rst = one + rst;
        } else {
            rst = zero + rst;
        }
        num >>= 1;
        bit--;
        if (bit == 0) {
            break;
        }
    }
    return rst;
}

std::string trimToIns(std::string str) {
    if (str.find('#') != str.npos) {
        str = str.substr(0, str.find('#'));
    }
    if (str.find(':') != str.npos) {
        str = str.substr(str.find(':') + 1, str.length());
    }
    return trim(str);
}