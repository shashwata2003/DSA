#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Maximum Profit in Job Scheduling:
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a 
profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that 
there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 */

// Comparator function should take references or pointers to pairs
static bool compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    return a.first > b.first;
}


/*
Wrong apporach:
THis apporach doesnot Account foe the max profit like for eg:
Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]

Here according to my apporach we will get a 120 schduling one the task with 100 + 20 

Buy this is not the max one we can get the max by  The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
*/
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profits) {
    vector<pair<int, pair<int, int>>> jobs;
    for (int i = 0; i < startTime.size(); i++) {
        // Properly create the pair and push it to the vector
        jobs.emplace_back(profits[i], make_pair(startTime[i], endTime[i]));
    }

    // Sort jobs based on profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    int totalProfit = jobs[0].first;
    int start = jobs[0].second.first;
    int end = jobs[0].second.second;

    for (int i = 1; i < jobs.size(); i++) {
        // Check for non-overlapping condition
        if ((jobs[i].second.first < start && jobs[i].second.second <= start) || jobs[i].second.first >= end) {
            totalProfit += jobs[i].first;
        }
    }

    return totalProfit;
}

/*
Correct apporach: 
1) First sort jobs according to finish time.
2) Now apply following recursive process. 
   // Here arr[] is array of n jobs
   findMaximumProfit(arr[], n)
   {
     a) if (n == 1) return arr[0];
     b) Return the maximum of following two profits.
         (i) Maximum profit by excluding current job, i.e., 
             findMaximumProfit(arr, n-1)
         (ii) Maximum profit by including the current job            
   }

*/

// Using Memorization
class Job {
    public:
        int start;
        int end;
        int profit;
        Job(int s, int e, int p) : start(s), end(e), profit(p) {}
    };

    static bool cmp(const unique_ptr<Job>& a, const unique_ptr<Job>& b) {
        return a->end < b->end;
    }

    int findindex(const vector<unique_ptr<Job>>& jobs, int n) {
        for (int i = n - 1; i >= 0; i--) {
            if (jobs[i]->end <= jobs[n]->start) {
                return i;
            }
        }
        return -1;
    }

    int solve(vector<unique_ptr<Job>>& jobs, int n, vector<int>& dp) {
        if (n == 1) {
            return jobs[0]->profit;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        // either we can include the current job or exclude the current job
        int include = jobs[n - 1]->profit;
        int i = findindex(jobs, n - 1);
        if (i != -1) {
            include += solve(jobs, i + 1, dp);
        }
        int exclude = solve(jobs, n - 1, dp);
        return dp[n] = max(exclude, include);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<unique_ptr<Job>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back(make_unique<Job>(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), cmp);

        vector<int> dp(n + 1, -1); // Memoization vector to store results of subproblems
        return solve(jobs, n, dp);
    }


// Using Tabulation:
    class Job {
    public:
        int start;
        int end;
        int profit;
        Job(int s, int e, int p) : start(s), end(e), profit(p) {}
    };

    static bool cmp(const Job& a, const Job& b) {
        return a.end < b.end;
    }

    int findLastNonConflictingJob(const vector<Job>& jobs, int index) {
        int low = 0, high = index - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid].end <= jobs[index].start) {
                if (jobs[mid + 1].end <= jobs[index].start)
                    low = mid + 1;
                else
                    return mid;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs;
        for (int i = 0; i < n; i++) {
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end(), cmp);

        vector<int> dp(n);
        dp[0] = jobs[0].profit;

        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i].profit;
            int l = findLastNonConflictingJob(jobs, i);
            if (l != -1) {
                includeProfit += dp[l];
            }
            dp[i] = max(dp[i - 1], includeProfit);
        }

        return dp[n - 1];
    }
int main(){

return 0;
}