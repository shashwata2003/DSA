#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

/* Apporach 1: 
Using map
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int n = mp.size();
        for(int i=0 ; i<n; i++){
            if(mp[nums[i]]> 1){
                return nums[i];
            }
        }
        return -1;
    }
};

/*Apporach 2:
 Linked List cycle method*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0];
        int slow=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow != fast);
        fast=nums[0];
        while(slow != fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
int main(){

return 0;
}