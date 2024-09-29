/*
Questions1:
Given a sequence of numbers in an array A. The task is to break short the array such the twice minimum value in the array should be greater than the maximum value in the array. The number of values removed from the array should be minimal. The removal of elements from the array can be done from the start or from the end of the array as per the condition mentioned above.

Input format :
The first line contains a single integer n, which represents the number of integers in the list.

The second set of input contains n integers on n lines, which represents the list of elements.

Output format :
The output consists of a single integer, which represents the minimum number of elements that need to be removed from the list to make the remaining elements in the list satisfy the condition that the minimum element is at least half of the maximum element.



Refer to the sample output for formatting specifications.

Sample test cases :
Input 1 :
7
2 
4 
5 
6 
8 
9 
1
Output 1 :
3
Input 2 :
4
4
7
5
6
Output 2 :
0
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;

int main(){
    vector<int> arr = {2,4,5,6,8,9,1};
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;

    // Use 'arr' instead of 'v'
    for (vector<int>::iterator i = arr.begin(); i != arr.end(); i++) {
        vector<int>::iterator j = upper_bound(arr.begin(), arr.end(), (2 * (*i)));

        // Update the answer (ensuring both operands are of the same type)
        ans = min(ans, n - (int)(j - i));
    }

    cout << ans;
    return 0;
}
