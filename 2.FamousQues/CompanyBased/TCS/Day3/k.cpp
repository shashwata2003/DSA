/*

Q11:
Problem Statement



Have the function BracketCombinations(num) read num which will be an integer greater than or equal to zero, and return the number of valid combinations that can be formed with num pairs of parentheses.



For example, if the input is 3, then the possible combinations of 3 pairs of parenthesis, namely: ()()(), are ()()(), ()(()), (())(), ((())), and (()()). There are 5 total combinations when the input is 3, so your program should return 5.

Input format :
The input consists of a single integer n, representing the number of pairs of brackets.

Output format :
The output displays a single integer representing the number of possible combinations of well-formed bracket sequences.



Refer to the sample output for the formatting specifications.

Code constraints :
0 ≤ n ≤ 8

Sample test cases :
Input 1 :
3
Output 1 :
5
Input 2 :
2
Output 2 :
2
Input 3 :
0
Output 3 :
1
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
void findvalidbrackets(int left, int right, int &cnt){
    if(left > right || left < 0 || right < 0){
        return;
    }
    if(left == 0 || right == 0){
        cnt++;
        return;
    }
    findvalidbrackets(left-1,right,cnt);
    findvalidbrackets(left,right-1,cnt);
}
int main(){
    int n;
    cin>>n;
    int cnt = 0;
    findvalidbrackets(n,n,cnt);
    cout<<cnt;
return 0;
}