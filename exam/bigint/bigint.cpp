#include "bigint.hpp"

bigint::bigint() : val("0"bigint& bigint::operator<<=(int shift){
    if (this->val == "0") return *this;
    this->val.append(shift, '0');
    return *this;
}
//bigint::bigint(const int s) : val(std::to_string(s)) {}
bigint::bigint(const unsigned int s){
    std::stringstream ss;
    ss << s;
    val = ss.str();
}
bigint::~bigint() {}
std::string bigint::getVal() const { return val; }
bigint::bigint(const bigint &b) : val(b.val) {}
bigint bigint::operator+(const bigint &b) const {
    // Implement addition logic here
    std::string result = "";
    std::string s1 = this->val;
    std::string s2 = b.val;
    if (s1.size() < s2.size()) std::swap(s1, s2);
    int carry = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while(i >= 0 || j >= 0 || carry){
        int digit1 = (i >= 0) ? s1[i] - '0' : 0;
        int digit2 = (j >= 0) ? s2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = std::to_string(sum % 10) + result;
        i--;
        j--;
    }
    return bigint(result);
}
bigint& bigint::operator+=(const bigint &b){
    *this = *this + b;
    return *this;
}
bigint bigint::operator++(int){
    bigint temp(*this);
    *this += bigint(1);
    return temp;
}
bigint& bigint::operator++(){
    *this += bigint(1);
    return *this;
}
bigint bigint::operator<<(int shift) const{
    if (this->val == "0") return *this; // Shifting zero remains zero
    bigint copy(*this);
    copy.val.append(shift, '0');
    return copy;
}
bigint bigint::operator<<=(int shift){
    if (*this->val == "0") return *this;
    this->val.append(shift, '0');
    return *this;
}
bigint& bigint::operator>>=(int shift){
    if (this->val == "0") return *this;
    if(shift >= this->val.size()){
        this->val = "0";
        return *this;
    }
    this->val = this->val.substr(0, this->val.size() - shift);
    return *this;
}
bool bigint::operator<(const bigint &b) const{
    if (this->val.size() < b.val.size()) return true;
    if (this->val.size() > b.val.size()) return false;
    std::string s1 = this->val;
    std::string s2 = b.val;
    for(int i = 0; i < s1.size(); i++){
        if (s1[i] < s2[i]) return true;
        if (s1[i] > s2[i]) return false;
    }
    return false;
}
bool bigint::operator>(const bigint &b) const{
    return !(*this <= b);
}
bool bigint::operator<=(const bigint &b) const{
    return *this < b || *this == b;
}
bool bigint::operator>=(const bigint &b) const{
    return !(*this < b);
}
bool bigint::operator==(const bigint &b) const{
    return this->val == b.val;
}
bool bigint::operator!=(const bigint &b)const{
    return !(*this == b);
}

std::ostream& operator<<(std::ostream &out, const bigint &b){
    out << b.getVal();
    return out;
}