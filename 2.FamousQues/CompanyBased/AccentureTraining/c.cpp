#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Wordakshri: The last letter of the word should be the first letter of the next word, there should not be any 
repeated words in the array
if a word doesnot follow the above rule then remove that word and return the array
 */
int main(){
    vector<string> arr = {"aabb","abbac","acca","bba","###"};
    set<string> arr1;
    for(const auto& str : arr) {
        arr1.insert(str);
    }
    if(arr.size()!=arr1.size()){
        cout<<"Repeated Words"<<endl;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == "###"){
            break;
        }
        if(arr[i].back()!=arr[i+1].front() && arr[i+1] != "###"){
            arr.erase(arr.begin()+i+1);
            i--;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
return 0;
}