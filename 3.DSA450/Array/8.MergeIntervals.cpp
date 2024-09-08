#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

/*
Apporach 1:
Pushing all the elements in a deque and pop two elements form the front and if ther can be merged
we merge them and push them back in 
Also managing the edge case of if there is only on element
Here we need to sort the element up front to get the ans as the input is not sorted.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        deque<vector<int>> dq;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        // Push all intervals into the deque
        for(int i = 0; i < n; i++) {
            dq.push_back(intervals[i]);
        }

        // Process the deque
        while(!dq.empty()) {
            // If there's only one interval left, push it directly to the result
            if (dq.size() == 1) {
                ans.push_back(dq.front());
                dq.pop_front();
                break;
            }
            
            vector<int> first = dq.front();
            dq.pop_front();
            vector<int> second = dq.front();
            dq.pop_front();
            
            // Merge intervals if they overlap
            if(first[1] >= second[0]) {  // Corrected overlap condition
                dq.push_front({min(first[0],second[0]), max(first[1], second[1])});
            } else {
                ans.push_back(first);
                dq.push_front(second);
            }
        }
        
        return ans;
    }
};

/*Apporach 2: A little better apporach:
Merging Logic: If the current interval does not overlap with the last interval in the result (ans), 
it is added to the result. If it overlaps, the intervals are merged by updating the end time of the last 
interval.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by the starting point
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for (auto interval : intervals) {
            // If ans is empty or current interval does not overlap with the last interval in ans
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                // Merge the intervals by updating the end time
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};


int main(){

return 0;
}