// CPP find maximum difference of subset sum 
#include <bits/stdc++.h> 
using namespace std; 

/*Given an array of n-integers. The array may contain repetitive elements but the highest frequency 
of any element must not exceed two. You have to make two subsets such that the difference of the sum 
of their elements is maximum and both of them jointly contain all elements of the given array along 
with the most important condition, no subset should contain repetitive elements. 

Examples: 

Input : arr[] = {5, 8, -1, 4}
Output : Maximum Difference = 18
Explanation : 
Let Subset A = {5, 8, 4} & Subset B = {-1}
Sum of elements of subset A = 17, of subset B = -1
Difference of Sum of Both subsets = 17 - (-1) = 18

Input : arr[] = {5, 8, 5, 4}
Output : Maximum Difference = 12
Explanation : 
Let Subset A = {5, 8, 4} & Subset B = {5}
Sum of elements of subset A = 17, of subset B = 5
Difference of Sum of Both subsets = 17 - 5 = 12

Solution:
Apporach 1: Using hash map 
-> sort the array
-> for i =0 to n-2
      // consecutive two elements are not equal
      // add absolute arr[i] to result
      if arr[i] != arr[i+1]
          result += abs(arr[i])
      // else skip next element too
      else
          i++;
          
// special check for last two elements
-> if (arr[n-2] != arr[n-1])
    result += arr[n-1]

-> return result;
TS: O(n)
Sp: O(n)

Apporach 2:
-> sort the array
-> for i =0 to n-2
      // consecutive two elements are not equal
      // add absolute arr[i] to result
      if arr[i] != arr[i+1]
          result += abs(arr[i])
      // else skip next element too
      else
          i++;
          
// special check for last two elements
-> if (arr[n-2] != arr[n-1])
    result += arr[n-1]

-> return result;
TS: O(nlogn)
SP: O(1)

*/


// function for maximum subset diff 
int maxDiff(int arr[], int n) 
{ 
	unordered_map<int, int> hashPositive; 
	unordered_map<int, int> hashNegative; 

	int SubsetSum_1 = 0, SubsetSum_2 = 0; 

	// construct hash for positive elements 
	for (int i = 0; i <= n - 1; i++) 
		if (arr[i] > 0) 
			hashPositive[arr[i]]++; 

	// calculate subset sum for positive elements 
	for (int i = 0; i <= n - 1; i++) 
		if (arr[i] > 0 && hashPositive[arr[i]] == 1) 
			SubsetSum_1 += arr[i]; 

	// construct hash for negative elements 
	for (int i = 0; i <= n - 1; i++) 
		if (arr[i] < 0) 
			hashNegative[abs(arr[i])]++; 

	// calculate subset sum for negative elements 
	for (int i = 0; i <= n - 1; i++) 
		if (arr[i] < 0 && 
			hashNegative[abs(arr[i])] == 1) 
			SubsetSum_2 += arr[i]; 

	return abs(SubsetSum_1 - SubsetSum_2); 
} 

int maxDiff2(int arr[], int n) 
{ 
    int result = 0; 
  
    // sort the array 
    sort(arr, arr + n); 
  
    // calculate the result 
    for (int i = 0; i < n - 1; i++) { 
        if (arr[i] != arr[i + 1]) 
            result += abs(arr[i]); 
        else
            i++; 
    } 
  
    // check for last element 
    if (arr[n - 2] != arr[n - 1]) 
        result += abs(arr[n - 1]); 
  
    // return result 
    return result; 
} 
// driver program 
int main() 
{ 
	int arr[] = { 4, 2, -3, 3, -2, -2, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Maximum Difference = " << maxDiff(arr, n); 
	return 0; 
} 
