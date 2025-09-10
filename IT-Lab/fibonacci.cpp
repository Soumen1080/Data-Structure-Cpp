#include <iostream>


int fibonacci(int n) {
    // Base case 1: The first term of the series is 0.
    if (n == 0) {
        return 0;
    }
    // Base case 2: The second term of the series is 1.
    if (n == 1) {
        return 1;
    }
    // Recursive step: Any other term is the sum of the two preceding ones.
    // The function calls itself with smaller values of n until it reaches a base case.
    return fibonacci(n - 1) + fibonacci(n - 2);
}


void printFibonacciSeries(int terms) {
    std::cout << "Fibonacci Series up to " << terms << " terms: ";
    // Loop from the first term (0) up to the nth term.5
    
    for (int i = 0; i < terms; ++i) {
        // For each iteration, calculate and print the ith Fibonacci number.
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;

    // Prompt the user to enter the number of terms.
    std::cout << "Enter the number of terms for the Fibonacci series: ";
    std::cin >> n;

    // Input validation: Ensure the number of terms is positive.
    if (n <= 0) {
        std::cout << "Please enter a positive number of terms." << std::endl;
    } else {
        // Generate and print the series.
        printFibonacciSeries(n);
    }

    return 0; // Indicate successful execution
}
