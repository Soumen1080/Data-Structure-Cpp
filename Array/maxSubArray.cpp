/*
Problem: Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/






// time complexity O(n^3)
// space complexity O(1)


#include<iostream>
#include <climits>
#include <algorithm>


using namespace std; 
  int max_sum = INT_MIN;
void printArray(int arr[], int n) {
  
   for(int start = 0 ; start < n ; start++){
     for( int end = start ; end < n ; end++){
        int curr_sum = 0 ;
        for(int i = start; i <= end; i++){
            curr_sum += arr[i];
         max_sum = max(curr_sum , max_sum);
        }
        cout << curr_sum << ",";
        
     }
      cout << endl;
   } 
cout << "max sum is " << max_sum << endl;

}

int main(){

    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(arr[0]); // Calculate the number of elements in the array
printArray(arr , n ) ;
}

// Explanation of the Code:
// 1. The code defines a function `printArray` that takes an array and its size as input.
// 2. It uses three nested loops to generate all possible subarrays of the input array.   The outer two loops define the start and end indices of the subarray, while the innermost loop calculates the sum of the elements in that subarray.
// 3. The current sum of each subarray is printed, and the maximum sum encountered so far is updated using the `max` function.
// 4. The `main` function initializes an array and calculates its size, then calls the `printArray` function to display the sums of all subarrays and the maximum sum found.          
// 5. The time complexity of this approach is O(n^3) due to the three nested loops, and the space complexity is O(1) since no additional data structures are used that grow with input size.
