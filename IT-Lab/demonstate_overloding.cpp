#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    // Constructor
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Overload the '+' operator
    ComplexNumber operator+(const ComplexNumber& other) const {
        ComplexNumber result;
        result.real = real + other.real;
        result.imaginary = imaginary + other.imaginary;
        return result;
    }

    // Method to display the complex number
    void display() const {
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
        std::cout << std::endl;
    }
};

int main() {
    ComplexNumber c1(3.5, 2.0);
    ComplexNumber c2(1.0, 4.5);

    std::cout << "Complex Number 1: ";
    c1.display();

    std::cout << "Complex Number 2: ";
    c2.display();

    // Using the overloaded '+' operator
    ComplexNumber c3 = c1 + c2;

    std::cout << "Sum of Complex Numbers: ";
    c3.display();

    return 0;
}