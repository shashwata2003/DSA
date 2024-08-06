#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the 
maximum total value in the knapsack. Return a double value representing the maximum value in knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. The details of structure/class is defined 
in the comments above the given function.

Examples :

Input: n = 3, w = 50, value[] = [60,100,120], weight[] = [10,20,30]
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with 
value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 
60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
Input: n = 2, w = 50, value[] = [60,100], weight[] = [10,20]
Output: 160.000000
Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 
160.00 from the given capacity of sack.

Expected Time Complexity : O(n log n)
Expected Auxilliary Space: O(n)
 */

struct Item{
    int value;
    int weight;
};

bool compare(pair<double,Item> a, pair<double,Item> b){
    return a.first > b.first;
}

double fractionalKnapsack(int w, Item arr[], int n) {
    //valperweight and the index
    vector<pair<double,Item>> map;
    for (int i = 0; i < n; i++)
    {
        double perweight = (1.0 * arr[i].value ) / arr[i].weight;
        pair<double,Item> p = make_pair(perweight, ar[i]);
        map.push_back(p);
    }

    sort(map.begin(),map.end(),compare);

    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(map[i].second.weight > w){
            // as the weight of the curr element is greater than the knacksack hence we need to use fractional
            //weight
            ans += w*map[i].first;
            w = 0;

        }else{
            // else we can use the full weights:
            ans = ans+map[i].second.value;
            w = w - map[i].second.weight;
        }
    }
    
    return ans;
}

int main(){

return 0;
}