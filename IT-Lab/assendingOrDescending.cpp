// #include <iostream>
// #include <algorithm> // For sort function
// using namespace std;

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int arr[] = {4, 1, 7, 3, 2, 0};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int choice;

//     cout << "Original Array: ";
//     printArray(arr, size);

//     cout << "Enter 1 to sort in Ascending order or 2 for Descending order: ";
//     cin >> choice;

//     if (choice == 1) {
//         sort(arr, arr + size); // Sort in ascending order
//         cout << "Array sorted in Ascending order: ";
//         printArray(arr, size);
//     } else if (choice == 2) {
//         sort(arr, arr + size, greater<int>()); // Sort in descending order
//         cout << "Array sorted in Descending order: ";
//         printArray(arr, size);
//     } else {
//         cout << "Invalid choice! Please enter 1 or 2." << endl;
//     }

//     return 0;
// }

// Explanation:

// Input Array: The array {4, 1, 7, 3, 2, 0} is predefined.
// User Choice: The user selects whether to sort in ascending or descending order.
// Sorting:

// sort(arr, arr + size) sorts in ascending order.
// sort(arr, arr + size, greater<int>()) sorts in descending order.


// Output: The sorted array is displayed based on the user's choice.

// This program is simple, efficient, and uses the built-in sort function from the <algorithm> library.
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <functional>  // Required for std::greater


void printArray(const std::vector<int>& arr, const std::string& message) {
    std::cout << message;
    // Range-based for loop to iterate through each element in the vector
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Initialize a vector with the given integer elements.
    // std::vector is a dynamic array from the C++ Standard Library.
    std::vector<int> numbers = {4, 1, 7, 3, 2, 0};

    // Display the original, unsorted array.
    printArray(numbers, "Original array:          ");

    // --- Ascending Sort ---
    // std::sort sorts the elements in a range [first, last) into ascending order.
    // .begin() returns an iterator to the beginning of the vector.
    // .end() returns an iterator to the end of the vector.
    std::sort(numbers.begin(), numbers.end());

    // Display the array after sorting in ascending order.
    printArray(numbers, "Sorted (ascending):      ");

    // --- Descending Sort ---
    // To sort in descending order, we provide a third argument to std::sort:
    // a comparator. std::greater<int>() is a function object that returns
    // true if the first argument is greater than the second.
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // Display the array after sorting in descending order.
    printArray(numbers, "Sorted (descending):     ");

    return 0; // Indicate successful execution
}
