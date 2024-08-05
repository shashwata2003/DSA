#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Check if it is possible to survive on Island:

Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week 
except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.

Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S 
days, or determine that it isn’t possible to survive.

Example 1:
Input: S = 10, N = 16, M = 2
Output: 2
Explaination: One possible solution is to 
buy a box on the first day (Monday), 
it’s sufficient to eat from this box up to 
8th day (Monday) inclusive. Now, on the 9th 
day (Tuesday), you buy another box and use 
the chocolates in it to survive the 9th and 
10th day.

Example 2:
Input: S = 10, N = 9, M = 8
Output: -1
Explaination: Let's start by detailing the days of the week and the net number of food units available after 
purchasing and consuming them:
Monday - Net 1 food unit available.
Tuesday - Net 2 food units available.
Wednesday - Net 3 food units available.
Thursday - Net 4 food units available.
Friday - Net 5 food units available.
Saturday - Net 6 food units available.
Sunday - 6 food units available and that is not sufficient amount of food units to survive and you can't buy 
more on Sunday.

Sol:
N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive


algo:
Also find the sundays : s/7
and buying days = total - sundays
if(s*m % n == 0){
return s*m/n}
else{
S*M/n +1}

*/

int minimumDays(int S, int N, int M){
    // If we can not buy at least a week 
    // supply of food during the first week 
    // OR We can not buy a day supply of food 
    // on the first day then we can't survive. 
    if (((N * 6) < (M * 7) && S > 6) || M > N) 
        return -1; 
    else { 
        // If we can survive then we can 
        // buy ceil(A/N) times where A is 
        // total units of food required. 
        int days = (M * S) / N; 
        if (((M * S) % N) != 0) 
            days++; 
        return days;
    } 
} 


int main(){
    int S = 10, N = 9, M = 8;
    cout<<minimumDays(S,N,M);
return 0;
}