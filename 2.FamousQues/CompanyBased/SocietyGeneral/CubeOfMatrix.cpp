#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Cube of a matrix
Given an M x N sized 2D array 'MATRIX', return the (i * i + j * j) value for elements in which the 
sum of cube of digits of the element is equal to the element itself. Here, 'i' is the row number from 
‘0’ to ‘M-1’, and 'j' is the column number from ‘0’ to ‘N-1’.

Note:
If no such number is present, return -1.
Sample input 1
2
4 4
1 4 6 14 10 30 370 29 12 16 18 20 22 26 28 34
3 4
12 50 66 80 95 22 30 153 200 55 11 44
Sample output 1
0 5
10
Explanation of sample input 1:
Test case 1: 
The element at position A[0][0] is 1. The cube of the digits of 1 is 1^3 = 1, which is the element itself. Here i = 0 and j = 0 so we add (0*0 + 0*0) = 0 to our answer. 
The element at position A[1][2] is 370. The cube of the digits is also 370 (3^3 + 7^3 + 0^3 = 370), which is the element itself. Here i = 1 and j = 2 so we add 1*1 + 2*2 = 5 to our answer.
While all the other elements do not satisfy the condition.


Test case 2: 
The element at position A[1][3] is 153. The cube of digits is 1^3+5^3+3^3 = 153, which is the element itself. While all other elements do not satisfy the condition. Hence, the output is  (1*1+3*3) = 10.  
Sample input 2
1
2 2
2 4 6 18
Sample output 2
-1
Explanation of sample input 2:
Sum of cube of digits of 2 = 2^3 = 8 ≠ 2
Sum of cube of digits of 4 = 4^3 = 64 ≠ 4
Sum of cube of digits of 6 = 6^3 = 216 ≠ 6
Sum of cube of digits of 18 = 1^3+8^3 = 513 ≠ 18

Since none of the elements among 2, 4, 6, 18 have the sum of the cube of digits as the number, it will return -1.

 */

bool issafe(int n){
    int sum = 0;
    int temp = n;
    while(temp){
        int digit = temp%10;
        temp = temp/10;
        sum = sum + (digit*digit*digit);
    }

    if(sum == n){
        return true;
    }
    return false;
}

vector<int> evaluate(vector< vector<int> > &matrix, int m, int n) {
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(issafe(matrix[i][j])){
                int temp = i*i + j*j;
                ans.push_back(temp);
            }
        }
    }
    if(ans.size() == 0){
        return {-1};
    }
    return ans;
}


int main(){
    vector<vector<int>> matrix = {{2, 4}, {6, 18}};
    int m = 2;
    int n = 2;
    vector<int> ans = evaluate(matrix,m,n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}