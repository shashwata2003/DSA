#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* The Celebrity Problem
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, 
find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  
is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Return the index of the celebrity, if there is no celebrity return -1.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 
Solution:
Apporach 1: Brute Force:
As given in the question celebrity doesnot know anyone and everyone knows celebrity. hence we will check each rows 
if all the elements of a row is 0 then he doesnot know any one, after that we will check the col of that particular 
element if every element on that col except itself is 1 then that means everyone knows that element hence it is a
celebrity return th index
check two conditions:
The row of the Celebrity will be all zero 
and the column of te Celebrity will be 1's except the diagonal.
Time Complexity: o(N2)

Apporach 2:
Here we are going to use a stack.
1. push all the elements in the stack(0,1,2) for n = 3
2. run a while till size =! 1 and store the top values in A and b 
3. if a knows b push b back in the stack and a is not a celebrity
4. if b knows a push a back in the stack and b is not a celebrity
5. after getting the top value we need to run a row and column check to make sure the answer is correct or not
6. return the last element in the stack 
 */

bool knows(int a, int b, vector<vector<int>> M, int n) {
    if (M[a][b] == 1) {
        return true;
    } else {
        return false;
    }
}

int findcelebrity(vector<vector<int>> M, int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        st.push(i);
    }
    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (knows(a, b, M, n)) {
            st.push(b);
        } else {
            st.push(a);
        }
    }
    int candidate = st.top();
    // row check - all elements should be zero
    int countzero = 0;
    for (int i = 0; i < n; i++) {
        if (M[candidate][i] == 0) {
            countzero++;
        }
    }

    if (countzero != n) {
        return -1;
    }

    // column check n-1 element should be 1;
    int countone = 0;
    for (int i = 0; i < n; i++) {
        if (M[i][candidate] == 1) {
            countone++;
        }
    }
    if (countone != n - 1) {
        return -1;
    }

    return candidate;
}

int main() {
    vector<vector<int>> arr = {{0 ,1,0},{0, 0, 0},{0, 1, 0}};
    int n = 3;
    int ans = findcelebrity(arr, n);
    cout << "The celebrity is: " << ans;
    return 0;
}