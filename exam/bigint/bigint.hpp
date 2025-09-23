#pragma once

#include <string>   
#include <iostream>
#include <sstream>

class bigint {
    private:
    std::string val;
    public:
    bigint();
    bigint(const std::string &);
    bigint(const unsigned int);
    bigint(const bigint &);
    ~bigint();
    std::string getVal() const;

    bigint operator+(const bigint &) const;
    bigint& operator+=(const bigint &b);
    bigint& operator++();
    bigint operator++(int);
    bigint operator<<(int) const;
    bigint& operator<<=(int);
    bigint& operator>>=(int);
    bool operator==(const bigint &) const;
    bool operator!=(const bigint &) const;
    bool operator<(const bigint &) const;
    bool operator<=(const bigint &) const;
    bool operator>(const bigint &) const;
    bool operator>=(const bigint &) const;


};
std::ostream & operator<<(std::ostream &, const bigint &);