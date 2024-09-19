#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Matrix Chain Multiplication | DP-8:
Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is 
(arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that 
the total number of element multiplications is minimum.

Examples:

Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000
Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.
Let the input 4 matrices be A, B, C and D.
The minimum number of  multiplications are obtained by 
putting parenthesis in following way (A(BC))D.
The minimum is 20*30*10 + 40*20*10 + 40*10*30

Input: arr[] = {1, 2, 3, 4, 3}
Output: 30
Explanation: There are 4 matrices of dimensions 1×2, 2×3, 3×4, 4×3. 
Let the input 4 matrices be A, B, C and D.  
The minimum number of multiplications are obtained by 
putting parenthesis in following way ((AB)C)D.
The minimum number is 1*2*3 + 1*3*4 + 1*4*3 = 30

Input: arr[] = {10, 20, 30}
Output: 6000  
Explanation: There are only two matrices of dimensions 10×20 and 20×30. 
So there  is only one way to multiply the matrices, cost of which is 10*20*30





https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
 */


/*
Two matrices of size m*n and n*p when multiplied, they generate a matrix of size m*p 
and the number of multiplications performed are m*n*p.

we will split the array using k b/w i and j

/ Place parenthesis at different places
    // between first and last matrix, 
    // recursively calculate count of multiplications 
    // for each parenthesis placement 
    // and return the minimum count
*/
int solve(int i, int j, int arr[]){
    if(i == j){
        return 0;
    }

    int mini = INT_MAX;
    // K is the element which divides the array into 2
    for (int k = i; k < j; k++)
    {
        int count = solve(i,k,arr) + solve(k+1,j,arr) + arr[i-1] * arr[j] * arr[k];
        mini = min(mini,count);
    }
    return mini;
    
}

int matrixMultiplication(int N, int arr[])
{
    int i = 1, j = N-1;
    int ans = solve(i,j,arr);
}

int main(){

return 0;
}