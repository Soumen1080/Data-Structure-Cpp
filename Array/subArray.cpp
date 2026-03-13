/*
LeetCode Problem 3000. Enumerate Contiguous Subarrays
Given an integer array nums, list every contiguous subarray in the order of increasing start index, and for ties in increasing end index. Represent each subarray by concatenating its elements without separators.

Input:
- n: 1 <= n <= 10^3
- nums: vector<int> of length n with |nums[i]| <= 10^4

Output:
- vector<string> containing the described representations.

Example:
Input: nums = [1,2,3]
Output: ["1","12","123","2","23","3"]
*/


// time complexity O(n^3)
// space complexity O(1)



#include<iostream>
using namespace std;

int printSubArray(int arr[] , int n ){ 

for (int start = 0 ; start < n ; start++ ){
for( int end = start ; end < n ; end++){
    for(int i = end ; i < n ; i++){
        cout << arr[i];
    }
cout << ",";
}
cout << endl;
}
return 0;

}
int main(){
int arr[5] = {1,2,3,4,5};
int n = 5 ;
printSubArray(arr , n ) ;

return 0 ; 

}


