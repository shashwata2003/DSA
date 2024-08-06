#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Job Sequencing Problem:

Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit 
associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job 
is the time before which job needs to be completed to earn the profit.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Sol:
we will sort by profit and do the job which has max profit (according to greedy algo):
we are going to utilise a deadline array which will list all the ideas which are are done and on the deadline 
index eg if task 1 has a deadline 1 then at index 1 task idea 1 will be stored, else if that slot is empty it 
will have -1
step:
1. sort the array based on the profit max profit first
2. then take the first job and check it deadline if it is -1 then add that there or else check all the index
before that eg: if a job has a deadling 4, first check weather 4 has -1 in it or not if not check 3 , 2, 1 
(we alway do the job as close to the deadlin)
3. update the profit and move to next 

Ts: O(nlog n * k)
SP: O(n)

 */

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool compare(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr,arr+n ,compare);

    //find the max deadline out of all jobs:
    int maxdead = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxdead = max(maxdead,arr[i].dead);
    }

    //deadline arr: +1 becase 1 base indexing
    vector<int> deadline(maxdead+1,-1);
    int maxprofit = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int currid = arr[i].id;
        int currdead = arr[i].dead;
        int currpro = arr[i].profit;
        for (int j = currdead; j > 0; j--)
        {
            if(deadline[j] == -1){
                //we have aempty deadline:
                count++;
                maxprofit = maxprofit + currpro;
                deadline[j] = currdead;
                break; // when we completed taht job we dont need to check furthure in that job
            }
        }
        
    }

    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxprofit);
    
    return ans;
}
int main(){

return 0;
}