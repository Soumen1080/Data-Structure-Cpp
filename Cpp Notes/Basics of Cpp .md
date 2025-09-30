# Basics of C++

C++ is a powerful, high-performance, general-purpose programming language. It was developed by Bjarne Stroustrup as an extension of the C language. C++ is an object-oriented programming language, but it also supports procedural and generic programming.

## Basic Syntax

Every C++ program consists of statements, and each statement ends with a semicolon (;). A block of code is a set of logically connected statements surrounded by opening and closing curly braces `{}`.

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!"; // This is a statement
    return 0;
}
```

### Comments
- `//`: Single-line comment.
- `/* ... */`: Multi-line comment.

## Data Types

C++ offers a rich set of built-in as well as user-defined data types.

- **`int`**: For integers (e.g., 10, -5, 1000).
- **`float`**: For single-precision floating-point numbers (e.g., 3.14, -0.5).
- **`double`**: For double-precision floating-point numbers (e.g., 3.14159).
- **`char`**: For single characters (e.g., 'a', 'Z', '9').
- **`bool`**: For boolean values (`true` or `false`).
- **`std::string`**: For sequences of characters. Requires the `<string>` header.

## Variables

A variable is a name given to a memory location.

### Declaration and Initialization

```cpp
int age; // Declaration
age = 25; // Initialization

// Declaration and Initialization in one line
std::string name = "John Doe";
```

## Operators

- **Arithmetic**: `+`, `-`, `*`, `/`, `%` (modulo)
- **Relational**: `==`, `!=`, `>`, `<`, `>=`, `<=`
- **Logical**: `&&` (AND), `||` (OR), `!` (NOT)
- **Assignment**: `=`, `+=`, `-=`, `*=`, `/=`

## Input/Output

C++ uses streams for input and output. `cin` is the standard input stream, and `cout` is the standard output stream. You need to include the `<iostream>` header.

```cpp
#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name); // Read a full line for strings

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;

    return 0;
}
```

## Control Structures

### Conditional Statements

- **`if-else`**:
```cpp
if (condition) {
    // code to execute if condition is true
} else {
    // code to execute if condition is false
}
```

- **`if-else if-else`**:
```cpp
if (condition1) {
    // code for condition1
} else if (condition2) {
    // code for condition2
} else {
    // code if no condition is met
}
```

- **`switch`**:
```cpp
switch (expression) {
    case constant1:
        // code
        break;
    case constant2:
        // code
        break;
    default:
        // code
}
```

### Loops

- **`for` loop**:
```cpp
for (initialization; condition; update) {
    // code to repeat
}
```

- **`while` loop**:
```cpp
while (condition) {
    // code to repeat
}
```

- **`do-while` loop**:
```cpp
do {
    // code to repeat
} while (condition);
```

## Functions

Functions are blocks of code that perform a specific task.

```cpp
// Function declaration (prototype)
int add(int a, int b);

// main function - entry point of the program
int main() {
    int sum = add(5, 3); // Function call
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
```

## Arrays

An array is a fundamental data structure in C++ that stores a collection of elements of the same data type in contiguous memory locations. This contiguous storage allows for efficient access to elements using an index.

### Declaring Arrays

To declare an array, you specify the type of the elements and the number of elements the array will hold.

```cpp
// Declares an array of 10 integers.
int myArray[10];
```

The size of the array must be a constant expression, as the memory is allocated at compile time.

### Initializing Arrays

You can initialize an array at the time of declaration.

```cpp
// Initialize with a list of values
int numbers[5] = {10, 20, 30, 40, 50};

// The size can be omitted if you provide an initializer list
int anotherNumbers[] = {1, 2, 3, 4}; // Compiler automatically deduces the size as 4

// Partial initialization - remaining elements are set to zero
int partial[10] = {1, 2}; // First two elements are 1, 2. The rest are 0.

// Initialize all elements to zero
int zeros[5] = {0};
```

### Accessing Array Elements

You can access individual array elements using the subscript operator `[]`. Array indices in C++ are zero-based, meaning the first element is at index 0.

```cpp
int numbers[5] = {10, 20, 30, 40, 50};

// Access and print the first element
std::cout << numbers[0]; // Outputs 10

// Modify the third element
numbers[2] = 35; // The array is now {10, 20, 35, 40, 50}
```

**Important**: C++ does not perform bounds checking on array access. Accessing an array beyond its bounds (e.g., `numbers[5]` in the example above) leads to undefined behavior, which can cause crashes or other bugs.

### Arrays and Loops

Loops are commonly used to iterate over the elements of an array.

```cpp
#include <iostream>

int main() {
    int scores[] = {88, 92, 75, 98, 85};
    int size = sizeof(scores) / sizeof(scores[0]); // Calculate the number of elements

    // Using a for loop
    for (int i = 0; i < size; ++i) {
        std::cout << "Element at index " << i << ": " << scores[i] << std::endl;
    }

    // Using a range-based for loop (C++11 and later)
    for (int score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Multi-dimensional Arrays

C++ supports multi-dimensional arrays, which are essentially arrays of arrays. A 2D array is the most common example, often used to represent a grid or a matrix.

```cpp
// Declare and initialize a 2D array with 3 rows and 4 columns
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Accessing an element
std::cout << matrix[1][2]; // Outputs 7 (element in the 2nd row, 3rd column)
```

### C-style Arrays vs. STL Containers

While C-style arrays are fundamental, they have limitations (fixed size, decay to pointers, no built-in bounds checking). The C++ Standard Template Library (STL) provides more powerful and safer alternatives:

-   **`std::vector`**: A dynamic array that can grow or shrink in size. It's the recommended choice for most use cases.
-   **`std::array`** (C++11 and later): A fixed-size array that has a similar interface to `std::vector` (e.g., it knows its own size) but its size is determined at compile-time, just like C-style arrays.

```cpp
#include <vector>
#include <array>
#include <iostream>

int main() {
    // A dynamic array
    std::vector<int> vec = {10, 20, 30};
    vec.push_back(40); // Add an element
    std::cout << "Vector size: " << vec.size() << std::endl;

    // A fixed-size array
    std::array<int, 4> arr = {1, 2, 3, 4};
    std::cout << "Array size: " << arr.size() << std::endl;

    return 0;
}
```

## Pointers

A pointer is a variable that stores the memory address of another variable.

```cpp
int var = 20;
int *ptr; // pointer declaration
ptr = &var; // store address of var in pointer variable

std::cout << "Value of var: " << var << std::endl;
std::cout << "Address of var: " << ptr << std::endl;
std::cout << "Value at address stored in ptr: " << *ptr << std::endl;
```

## Object-Oriented Programming (OOP)

OOP is a programming paradigm based on the concept of "objects", which can contain data and code.

- **Class**: A blueprint for creating objects.
- **Object**: An instance of a class.
- **Encapsulation**: Bundling of data and methods that operate on the data into a single unit (class).
- **Inheritance**: A mechanism where a new class inherits properties and behavior from an existing class.
- **Polymorphism**: The ability of an object to take on many forms.

## Standard Template Library (STL)

The STL is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators.

## Sorting Example with `std::sort`

The C++ STL provides a very efficient sorting algorithm `std::sort` in the `<algorithm>` header. It can sort any random-access container (like `std::vector` or a plain C-style array).

### Sorting a `std::vector`

Here is a complete example of how to sort a vector of integers.

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

int main() {
    // Create a vector of integers
    std::vector<int> numbers = {5, 2, 8, 1, 9, 4};

    // Print the vector before sorting
    std::cout << "Before sorting: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Print the vector after sorting
    std::cout << "After sorting (ascending): ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the vector in descending order using a lambda function
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });

    // Print the vector after sorting in descending order
    std::cout << "After sorting (descending): ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Detailed Explanation:

Let's break down the code step-by-step to understand how it works.

1.  **`#include <vector>` and `#include <algorithm>`**:
    *   In C++, you use `#include` to bring in code from the Standard Template Library (STL) or other libraries.
    *   `#include <vector>` gives us access to `std::vector`, a flexible and powerful dynamic array.
    *   `#include <algorithm>` provides a rich collection of functions that operate on ranges of elements, including our sorting function, `std::sort`.

2.  **`std::vector<int> numbers = { ... };`**:
    *   This line declares a variable named `numbers`.
    *   Its type is `std::vector<int>`, meaning it's a vector that can only hold integer (`int`) values.
    *   We initialize it with the list of numbers `{5, 2, 8, 1, 9, 4}`.

3.  **`std::sort(numbers.begin(), numbers.end());`**:
    *   This is the first call to the `std::sort` function, which sorts the vector in its default ascending order.
    *   **Iterators (`begin()` and `end()`):** The `std::sort` function doesn't take the vector itself as an argument, but rather "iterators" that specify the range of elements to sort. You can think of iterators as pointers that mark positions in the vector.
        *   `numbers.begin()`: This returns an iterator pointing to the very first element of the vector (the `5`).
        *   `numbers.end()`: This returns an iterator pointing to a conceptual position *just after* the last element of the vector.
    *   **The Range `[begin, end)`**: This notation means the range includes the starting element but excludes the ending one. So, `std::sort` operates on all elements from the one pointed to by `begin()` up to, but not including, the one pointed to by `end()`. This effectively covers the entire vector.

4.  **`std::sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });`**:
    *   This is the second call to `std::sort`, but this time we provide a third argument to customize the sorting logic.
    *   **Custom Comparison Function**: `std::sort` internally compares pairs of elements to decide their order. By default, it uses `<` (less than) to sort in ascending order. We can provide our own logic to change this.
    *   **Lambda Function**: The part `[](int a, int b) { return a > b; }` is a C++11 feature called a lambda function. It's a concise way to define an anonymous, inline function right where you need it.
        *   `[]`: The capture clause. It's empty here, which is common for simple comparison lambdas.
        *   `(int a, int b)`: The parameter list. `std::sort` will call this lambda with two elements from the vector to be compared.
        *   `{ return a > b; }`: The function body. This is the core of our custom logic. It returns `true` if `a` should be placed *before* `b` in the sorted sequence. By returning `true` when `a` is greater than `b`, we are telling `std::sort` to arrange the elements from largest to smallest, resulting in a descending sort.

This covers the fundamental aspects of C++. Happy coding!
