#ifndef FIBONACCIGENERATOR_H
#define FIBONACCIGENERATOR_H

#include <vector>
#include <stdexcept>
#include <gtest/gtest_prod.h>

template<typename T>
class FibonacciGenerator {
public:
    FibonacciGenerator();
    std::vector<T> generate(int n);

protected:
    T calculateNext(const T& a, const T& b);
    FRIEND_TEST(FibonacciTest, CalculateNextTest);

private:
    T privateMethod(T value);
    FRIEND_TEST(FibonacciTest, PrivateMethodTest);
};

#include "FibonacciGenerator.tpp"

#endif // FIBONACCIGENERATOR_H
