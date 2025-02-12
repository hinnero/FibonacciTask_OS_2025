#include <iostream>
#include <sstream>
#include "FibonacciGenerator.h"

int getNumberFromInput(int argc, char* argv[]) {
    int n = 15;
    if (argc > 1) {
        std::istringstream iss(argv[1]);
        iss >> n;
        if (iss.fail() || n < 0) {
            throw std::invalid_argument("Invalid input through command-line arguments. Please enter a non-negative integer.");
        }
    } else {
        std::cout << "Enter the number of Fibonacci numbers to generate: ";
        std::cin >> n;
        if (std::cin.fail() || n < 0) {
            throw std::invalid_argument("Invalid input through console. Please enter a non-negative integer.");
        }
    }
    return n;
}

void printFibonacciSequence(const std::vector<long long>& sequence) {
    std::cout << "The first " << sequence.size() << " Fibonacci numbers:" << std::endl;
    for (const auto& num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    try {
        int n = getNumberFromInput(argc, argv);

        FibonacciGenerator<long long> fibGen;
        std::vector<long long> fibSequence = fibGen.generate(n);

        printFibonacciSequence(fibSequence);
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}