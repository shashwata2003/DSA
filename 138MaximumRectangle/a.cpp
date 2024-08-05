#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Maximal Rectangle:
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's 
and return its area.

Ex1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1

TS: O(n*(N*M)) 
 */

    vector<int> findnextsmallest(vector<int> &arr) {
        stack<int> st;
        int n = arr.size();
        st.push(-1);
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i); // Push the index instead of value
        }
        
        return ans;
    }

    vector<int> findprevsmallest(vector<int> &arr) {
        stack<int> st;
        int n = arr.size();
        st.push(-1);
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i); // Push the index instead of value
        }
        
        return ans;
    }

    int findgreatestarea(vector<int> &arr) {
        int n = arr.size();
        vector<int> next = findnextsmallest(arr);
        vector<int> prev = findprevsmallest(arr);
        int ansarea = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int len = arr[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            int area = len * width;
            ansarea = max(ansarea, area);
        }
        
        return ansarea;
    }

int maximalRectangle(vector<vector<char>>& matrix) {
    //we need to create and find make area of each row of the matrix
    // Hence we will create a new histogram for each by add the prev row in it 
    int maxarea = INT_MIN;
    vector<int> histogram(matrix[0].size(),0);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == '1'){
                // eg for i = 2 we need to add the the height of i = 1 also and make it 2
                histogram[j]++;
            }else{
                //we it is zero the it all together becomes zero like:
                //In notebool eg i = 4 when the second ele is 0 the entire height becomes zero
                histogram[j] = 0;
            }
        }
        //Here the histogram is created for the curr row, also we keep it saved to add upon the next row,
        // hence the histogram is defined outside the loop

        maxarea = max(maxarea,findgreatestare(histogram)); //find the area for the curr histogram ans store the max
        
    }
    return maxarea;
}

int main(){

return 0;
}