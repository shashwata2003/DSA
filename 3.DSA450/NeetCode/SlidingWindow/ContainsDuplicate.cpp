#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
/*Other Apporachs: Sorting the array*/


/*Apporach 2:
Using Sliding Window*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i : nums){
            if(st.find(i) != st.end()){
                return true;
            }
            st.insert(i);
        }
        return false;
    }
};

/*Apporach 1:
Using map and keeping track count of each element
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        for(auto i: mp){
            if(i.second > 1){
                return true;
            }
        }
        return false;
    }
};

int main(){

return 0;
}