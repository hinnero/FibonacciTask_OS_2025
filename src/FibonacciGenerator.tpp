#ifndef FIBONACCIGENERATOR_TPP
#define FIBONACCIGENERATOR_TPP

#include "FibonacciGenerator.h"

template<typename T>
FibonacciGenerator<T>::FibonacciGenerator() {
}

template<typename T>
std::vector<T> FibonacciGenerator<T>::generate(int n) {
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }
    std::vector<T> sequence;
    if (n == 0) return sequence;

    sequence.push_back(0);
    if (n == 1) return sequence;

    sequence.push_back(1);

    for (int i = 2; i < n; ++i) {
        T next = calculateNext(sequence[i-2], sequence[i-1]);
        sequence.push_back(next);
    }
    return sequence;
}

template<typename T>
T FibonacciGenerator<T>::calculateNext(const T& a, const T& b) {
    return a + b;
}

template<typename T>
T FibonacciGenerator<T>::privateMethod(T value) {
    return value * 2;
}

#endif // FIBONACCIGENERATOR_TPP
