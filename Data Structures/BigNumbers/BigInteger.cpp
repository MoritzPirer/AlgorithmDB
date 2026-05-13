#include <iostream>
#include <exception>

#include "BigInteger.hpp"

BigInteger::BigInteger(long initial) {
    if (initial < 0) {
        m_is_negative = true;
        initial = -initial;
    }
    else {
        m_is_negative = false;
    }
    
    while (initial != 0) {
        m_data.push_back(static_cast<byte>(initial & 0xFF));
        initial >>= 8;
    }

    std::reverse(m_data.begin(), m_data.end());
}

BigInteger::BigInteger(std::string number) {
    for (size_t i = 0; i < number.length(); i++) {
        if (number[i] == '-' && i != 0) {
            throw std::invalid_argument("Initialize with decimal string");
        }
        if (number[i] < '0' || number[i] > '9') {
            throw std::invalid_argument("Initialize with decimal string");
        }
    }
    
    if (number.empty()) {
        m_is_negative = false;
        return;
    }

    m_is_negative = (number[0] == '-');

    //string to binary
}

std::string BigInteger::toString() const {
    std::string current = "0";
    for (byte b : m_data) {
        for (int i = 7; i >= 0; i--) {
            doubleString(current);
            if ((b >> i & 1) == 1) {
                incrementString(current);
            }
        }
    }
    
    if (m_is_negative) {
        return "-" + current;
    }

    return current;
}

void BigInteger::doubleString(std::string& str) const { 
    if (str.empty()) {
        return;
    }

    auto charToInt = [](char c) -> int { return c - '0'; };
    auto intToChar = [](int i) -> char { return i + '0'; };
    
    int carry = 0;
    for (int i = str.length() - 1; i >= 0; i--) {

        int doubled = charToInt(str[i]) * 2;
        
        str[i] = intToChar((doubled + carry) % 10);
        carry = (doubled + carry) / 10;
    }

    if (carry != 0) {
        str = std::string(1, intToChar(carry)) + str;
    }
}

void BigInteger::incrementString(std::string& str) const {
    if (str.empty()) {
        return;
    }

    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == '9') {
            str[i] = '0';
        }
        else {
            str[i] += 1;
            return;
        }
    }

    str = "1" + str;
    return;
}

BigInteger& BigInteger::preIncrement() {
    plusEquals(1);
    return *this;
}

BigInteger BigInteger::postIncrement() {
    BigInteger before = *this;
    plusEquals(1);
    return before;
}

BigInteger& BigInteger::preDecrement() {
    minusEquals(1);
    return *this;
}

BigInteger BigInteger::postDecrement() {
    BigInteger before = *this;
    minusEquals(1);
    return before;
}

BigInteger BigInteger::negate() const {
    BigInteger negated = *this;
    negated.m_is_negative = !negated.m_is_negative;

    return negated;
}

BigInteger BigInteger::operator-() const {
    return negate();
}

bool BigInteger::greaterThan(const BigInteger& other) const {
    if (this->m_is_negative != other.m_is_negative) {
        return other.m_is_negative;
    }

    if (this->m_data.size() != other.m_data.size()) {
        return this->m_data.size() > other.m_data.size();
    }

    for (int i = 0; i < this->m_data.size(); i++) {
        if (this->m_data[i] == other.m_data[i]) {
            continue;
        }

        return (this->m_data[i] > other.m_data[i]);
    }

    return false;
}

bool BigInteger::operator>(const BigInteger& other) const {
    return greaterThan(other);
}

bool BigInteger::greaterEquals(const BigInteger& other) const {
    return greaterThan(other) || equals(other);
}

bool BigInteger::operator>=(const BigInteger& other) const {
    return greaterEquals(other);
}

bool BigInteger::lessThan(const BigInteger& other) const {
    if (this->m_is_negative != other.m_is_negative) {
        return this->m_is_negative;
    }

    if (this->m_data.size() != other.m_data.size()) {
        return this->m_data.size() < other.m_data.size();
    }

    for (int i = 0; i < this->m_data.size(); i++) {
        if (this->m_data[i] == other.m_data[i]) {
            continue;
        }

        return (this->m_data[i] < other.m_data[i]);
    }

    return false;
}

bool BigInteger::operator<(const BigInteger& other) const {
    return lessThan(other);
}

bool BigInteger::lessEquals(const BigInteger& other) const {
    return lessThan(other) || equals(other);
}

bool BigInteger::operator<=(const BigInteger& other) const {
    return lessEquals(other);
}

bool BigInteger::equals(const BigInteger& other) const {
    if (this->m_is_negative != other.m_is_negative) {
        return false;
    }

    if (this->m_data.size() != other.m_data.size()) {
        return false;
    }

    for (int i = 0; i < this->m_data.size(); i++) {
        if (this->m_data[i] != other.m_data[i]) {
            return false;
        }
    }

    return true;
}

bool BigInteger::operator==(const BigInteger& other) const {
    return equals(other);
}

bool BigInteger::notEquals(const BigInteger& other) const {
    return !equals(other);
}

bool BigInteger::operator!=(const BigInteger& other) const {
    return notEquals(other);
}

BigInteger BigInteger::abs() const {
    BigInteger absolute = *this;
    absolute.m_is_negative = false;
}

int main() {
    BigInteger b = BigInteger(123456789);
    std::cout << b.toString();
    return 0;
}