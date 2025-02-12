#include <gtest/gtest.h>
#include "FibonacciGenerator.h"

TEST(FibonacciTest, ValidInput) {
    FibonacciGenerator<long long> fibGen;
    std::vector<long long> result = fibGen.generate(10);

    std::vector<long long> expected = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

    ASSERT_EQ(expected.size(), result.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], result[i]);
    }
}

TEST(FibonacciTest, NegativeInput) {
    FibonacciGenerator<long long> fibGen;
    EXPECT_THROW({
        fibGen.generate(-5);
    }, std::invalid_argument);
}

TEST(FibonacciTest, CalculateNextTest) {
    FibonacciGenerator<long long> fibGen;
    long long next = fibGen.calculateNext(5, 8);
    EXPECT_EQ(13, next);
}

TEST(FibonacciTest, PrivateMethodTest) {
    FibonacciGenerator<long long> fibGen;
    long long result = fibGen.privateMethod(10);
    EXPECT_EQ(20, result);
}
