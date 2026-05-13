///
/// @file: BigInteger.hpp
/// @description: Allows for calculations with numbers too large to fit into a long
///
/// @date: 20026-05-09
/// @author: Moritz Pirer
///

#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <vector>
#include <string>

class BigInteger {
private:
    using byte = uint8_t;
    std::vector<byte> m_data;
    bool m_is_negative = false;
    
    void doubleString(std::string& str) const;
    void incrementString(std::string& str) const;
public:
    BigInteger(long initial = 0);
    BigInteger(std::string number);

    BigInteger(const BigInteger&) = default;
    ~BigInteger() = default;

    std::string toString() const;

    BigInteger plus(const BigInteger& other) const;
    BigInteger plus(const long& other) const;

    BigInteger& plusEquals(const BigInteger& other) const;
    BigInteger& plusEquals(const long& other) const;

    BigInteger minus(const BigInteger& other) const;
    BigInteger minus(const long& other) const;

    BigInteger& minusEquals(const BigInteger& other) const;
    BigInteger& minusEquals(const long& other) const;

    BigInteger multiply(const BigInteger& other) const;
    BigInteger multiply(const long& other) const;

    BigInteger& multiplyEquals(const BigInteger& other) const;
    BigInteger& multiplyEquals(const long& other) const;

    BigInteger divide(const BigInteger& other) const;
    BigInteger divide(const long& other) const;

    BigInteger& divideEquals(const BigInteger& other) const;
    BigInteger& divideEquals(const long& other) const;

    BigInteger modulo(const BigInteger& other) const;
    BigInteger modulo(const long& other) const;

    BigInteger& moduloEquals(const BigInteger& other) const;
    BigInteger& moduloEquals(const long& other) const;

    std::pair<BigInteger, BigInteger> divideAndRemainder(const BigInteger& other);

    BigInteger& preIncrement();
    BigInteger postIncrement();
    BigInteger& preDecrement();
    BigInteger postDecrement();

    BigInteger negate() const;
    BigInteger operator-() const;


    bool greaterThan(const BigInteger& other) const;
    bool operator<(const BigInteger& other) const;

    bool greaterEquals(const BigInteger& other) const;
    bool operator<=(const BigInteger& other) const;

    bool lessThan(const BigInteger& other) const;
    bool operator>(const BigInteger& other) const;

    bool lessEquals(const BigInteger& other) const;
    bool operator>=(const BigInteger& other) const;

    bool equals(const BigInteger& other) const;
    bool operator==(const BigInteger& other) const;

    bool notEquals(const BigInteger& other) const;
    bool operator!=(const BigInteger& other) const;


    BigInteger abs() const;
};

#endif //BIG_INTEGER_HPP
