#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

vector<int> rearrange(vector<int> num)
{
    unordered_map<int, int> mp; // [val, freq]
    priority_queue<pair<int, int>> pq;
    vector<int> output;

    for (auto x : num) {
        mp[x]++;
    }

    for (auto x : mp) {
        pq.push({x.second, x.first});
    }

    pair<int, int> prev = {-1, -1};

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();
        output.push_back(curr.second);

        if (prev.first > 0) {
            pq.push(prev);
        }
        curr.first--;
        prev = curr;
    }

    if (num.size() == output.size()) {
        return output;
    } else {
        return {-2147483648};
    }
}

int main(){

return 0;
}

