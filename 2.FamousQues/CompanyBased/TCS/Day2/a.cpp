/*
You will be given an array of integers and a target value. Determine the number of pairs of array elements that have a difference equal to a target value.
For example, given an array of [1, 2, 3, 4] and a target value of 1, we have three values meeting the condition: 2-1 = 1, 3-2 = 1, and 4-3 = 1.

Function Description

Write a function pair. It must return an integer representing the number of element pairs having the required difference.



Pairs has the following parameter(s):

k: an integer, the target difference

arr: an array of integers

Input format :
The first line contains two space-separated integers n and k, the size of arr, and the target value.

The second line contains n space-separated integers of the array arr[I].

Output format :
The output displays an integer representing the number of element pairs from the array arr that have a difference of k.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n, k ≤ 10.

1 ≤ Arr[i] ≤ 100.

Sample test cases :
Input 1 :
4 1
1 2 3 4
Output 1 :
3
Input 2 :
5 2
1 5 3 4 2 
Output 2 :
3
*/
/* A sorting based program to count pairs with difference k*/
#include <iostream>
#include <algorithm>
using namespace std;
 
/* Returns count of pairs with difference k in arr[] of size n. */
int countPairsWithDiffK(int arr[], int n, int k)
{
    int count = 0;
    sort(arr, arr+n);  // Sort array elements

    int l = 0;
    int r = 0;
    while(r < n)
    {
         if(arr[r] - arr[l] == k)
        {
              count++;
              l++;
              r++;
        }
         else if(arr[r] - arr[l] > k)
              l++;
         else // arr[r] - arr[l] < sum
              r++;
    }   
    return count;
}

// Driver program to test above function
int main()
{
    int arr[] =  {1, 5, 3, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << "Count of pairs with given diff is "
         << countPairsWithDiffK(arr, n, k);
    return 0;
}
