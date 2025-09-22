
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ostream>

class bigint {
    private:
        std::string Val;
    public:
        bigint(const std::string& value) : Val(value) {}
        friend std::ostream& operator<<(std::ostream& os, const bigint& bg);
};

std::ostream& operator<<(std::ostream& os, const bigint& bg) {
    os << bg.Val;
    return os;
}
