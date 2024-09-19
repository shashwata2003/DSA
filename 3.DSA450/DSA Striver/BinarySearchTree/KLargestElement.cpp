#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest 
element without doing any modification in Binary Search Tree.

Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4
Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10
 */

class Solution
{
    private:
        int solve(Node *root, int K, int &i){
            if(root == NULL){
                return -1;
            }
            
            int right = solve(root->right, K, i);
            
            if(right != -1){
                return right;
            }
            
            i++;
            if(i == K){
                return root->data;
            }
            
            return solve(root->left,K,i);
        }
    public:
    int kthLargest(Node *root, int K)
    {
        int i = 0;
        return solve(root,K,i);
    }
};

int main(){

return 0;
}