#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 
'Inversions' that may exist.

An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).


Hints:
1. Start with the brute force approach.
2. Use a modified merge sort.
3. Iterate through the elements in sorted order and use a Fenwick tree to track the inversions.

 */

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    long long cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n;j++){
            if(arr[i] > arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}


int main(){

return 0;
}