#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Shop in Candy Store:

In a candy store, there are N different types of candies available and the prices of all the N different
types of candies are provided to you.
You are now provided with an attractive offer.
For every candy you buy from the store and get K other candies ( all are different types ) for free.
Now you have to answer two questions.
Firstly, you have to find what is the minimum amount of money you have
to spend to buy all the N different candies.
Secondly, you have to find what is the maximum amount of money
you have to spend to buy all the N different candies.

In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

Example 1:

Input:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7

Explanation:
As according to the offer if you buy
one candy you can take at most two
more for free. So in the first case,
you buy the candy which costs 1 and
takes candies worth 3 and 4 for free,
also you buy candy worth 2 as well.
So min cost : 1+2 =3.
In the second case, you can buy the
candy which costs 4 and takes candies
worth 1 and 2 for free, also you need
to buy candy worth 3 as well.
So max cost : 3+4 =7.
Example 2:

Input:
N = 5
K = 4
candies[] = {3 2 1 4 5}

Output:
1 5

Explanation:
For minimimum cost buy the candy with
the cost 1 and get all the other candies
for free.
For maximum cost buy the candy with
the cost 5 and get all other candies
for free.

SOl:
we need to find the min cost and max money needed to buy the all the n candies:

to find the min cost: using greedy algo, we will first select the candy with least cost,
and as the next two will be free so we will select the next two max cost of candies and
then buy the next least cost candies.

To find the max cost : using the greedy algo we will select the candy with max cost and for the next 2 free
candies we will select the min cost candies.
continue these till end.

Algo:
1. sort the array in ascending order.
2. to find min money: we will buy from the front and select the free one from the back
3. to find max money: we will buy form the end and select the free one from the front.

Ts: O(nlog n)
SP: O(1)
*/

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies,candies+N);

    int mini = 0;
    int free = N-1;
    int buy = 0;
    while (buy <= free)
    {
        mini = mini + candies[buy];
        buy++;
        free = free - K;
    }

    int maxi = 0;
    free = 0;
    buy = N-1;
    while (free<=buy)
    {
        maxi = maxi + candies[buy];
        buy--;
        free = free+K;
    }

    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);

    return ans;  
}

int main()
{
    int N = 4;
    int K = 2;
    int candies[] = {3, 2, 1, 4};
    vector<int> ans = candyStore(candies, N, K);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}