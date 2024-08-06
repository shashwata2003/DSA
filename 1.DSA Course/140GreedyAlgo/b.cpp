#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Maximum Meetings in One Room:

There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start 
time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings 
that can be accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting 
is strictly greater than the finish time of the previous meeting. Print all meeting numbers.

Note: If two meetings can be chosen for the same slot then choose meeting that finishes earlier.

Example 1:

Input:
N = 6
S = {1,3,0,5,8,5}
F = {2,4,6,7,9,9} 
Output:
{1,2,4,5}
Explanation:
We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from
(5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.
Example 2:

Input:
N = 1
S = {3}
F = {7}
Output:
{1}
Explanation:
Since there is only one meeting, we can attend the meeting.
 */

 bool compare(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
    //when the end time are same we sort on the basis of start time 
        if (a.first.second == b.first.second) 
            return a.first.first < b.first.first;
        return a.first.second < b.first.second;
    }

vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
    vector<int> ans;
    // start, end , index
    vector<pair<pair<int,int>,int>> map; // storing the index 1- based of each pair
    for (int i = 0; i < N; i++)
    {
        pair<pair<int,int>,int> p = make_pair(make_pair(S[i],F[i]),i+1);
        map.push_back(p);
    }

    sort(map.begin(),map.end(),compare);
    ans.push_back(map[0].second);
    int endans = map[0].first.second;
    for (int i = 0; i < N; i++)
    {
        if(endans < map[i].first.first){
            ans.push_back(map[i].second);
            endans = map[i].first.second;
        }
    }
    //return the sorted ans.
    sort(ans.begin(),ans.end());
    return ans;
    
}

int main(){
    int N = 10;
vector<int> S = {12, 6, 16,  12, 6,  9, 16, 6, 17, 5};
vector<int> F = {17, 13, 16, 18, 17,10, 18, 12, 18, 11};
vector<int> ans = maxMeetings(N,S,F);
for (int i = 0; i < ans.size(); i++)
{
    cout<<ans[i]<<" ";
}

return 0;
}