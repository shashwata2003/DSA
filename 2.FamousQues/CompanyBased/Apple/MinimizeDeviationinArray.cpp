#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
Example 2:

Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
Example 3:

Input: nums = [2,10,8]
Output: 3
 */

/*Using priority queue:
1. first convert all the odd no. in the array into the even by multiple by 2 and push all of the num
in the max heap hence the top will be the max val of the arr.
2. also find the min val of the array while pushing element in the queue.
3. now pop the top ans the max element and find the max deviation 
4. now we get any odd no. that means we have got that form the even operation /2 hence break the loop here
5. return ans
*/

int minimumDeviation(vector<int> & nums) {
    priority_queue<int> pq;
    int minval = INT_MAX;

    //finding the min val and filling the priority queue
    for(int num : nums){
        if(num % 2 == 1){
            num = num*2;
        }
        pq.push(num);
        minval = min(minval,num);
    }

    int mindevaition = INT_MAX;
    while (true)
    {
        int maxval = pq.top();
        pq.pop();
        // updating ans
        mindevaition = min(mindevaition,maxval - minval);

        //finding a odd no. after the odd operation
        if(maxval % 2 == 1){
            break;
        }
        // even operation
        maxval = maxval/2;
        //updating the minval
        minval = min(maxval,minval);
        pq.push(maxval); // push the maxval in the 
    }
    
    return mindevaition;
}

int main(){
    vector<int> num = {1,2,3,4};
    cout<<minimumDeviation(num);
return 0;
}