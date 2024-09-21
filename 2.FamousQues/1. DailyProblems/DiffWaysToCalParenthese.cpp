#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

/*\

*/

class Solution {
private:
    // Helper function to check if a character is an operator (+, -, *, /)
    bool isoperation(char &a) {
        return (a == '-' || a == '+' || a == '*' || a == '/');
    }
    
    // Recursive function to compute all possible results from the expression
    vector<int> solve(string expression, map<string,vector<int>> &memo) {
        // Check if the result for this expression is already computed (memoization)
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        vector<int> res;  // To store the possible results for this expression
        int n = expression.size();

        // Loop through the entire expression to find operators
        for (int op = 0; op < n; op++) {
            // If the current character is an operator, split the expression
            if (isoperation(expression[op])) {
                // Recursively solve for the left and right subexpressions
                vector<int> pre = solve(expression.substr(0, op), memo);
                vector<int> suf = solve(expression.substr(op + 1), memo);

                // Combine the results from left and right subexpressions using the operator
                for (int i = 0; i < pre.size(); i++) {
                    for (int j = 0; j < suf.size(); j++) {
                        if (expression[op] == '+') {
                            res.push_back(pre[i] + suf[j]);  // Apply addition
                        }
                        if (expression[op] == '-') {
                            res.push_back(pre[i] - suf[j]);  // Apply subtraction
                        }
                        if (expression[op] == '*') {
                            res.push_back(pre[i] * suf[j]);  // Apply multiplication
                        }
                    }
                }
            }
        }

        // Base case: if no operator is found, it's a single number
        if (res.size() == 0) {
            res.push_back(atoi(expression.c_str()));  // Convert string to integer
        }

        // Store the computed result in the memoization map
        memo[expression] = res;

        // Return the result
        return res;
    }

public:
    // Function to compute different ways to add parentheses and get all possible results
    vector<int> diffWaysToCompute(string expression) {
        map<string,vector<int>> memo;  // Memoization map to store intermediate results
        return solve(expression, memo);  // Call the recursive solve function
    }
};



int main(){

return 0;
}