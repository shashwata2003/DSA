#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
maximum occuring Character in an string:(imp)
Here we are given a string a, we need to find the char which occure the most like
a = test
ans  = t 
solution: we need to create a int arr of size 26 intialised with 0, in which each index is maped to a char which like 0-a, 1-b etc
now when ever a char occurs we increment this count in the arr.
now we need to find the max value in the array and index of it.
 */
int main(){
    string s;
    cin>>s;
    int arr[26]={0};
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }
    //find the max int in the array.
    int max = -1,ans = 0;
    for (int i = 0; i < 26 ; i++)
    {
        if (max <arr[i])
        {
            ans = i;
            max = arr[i];
        }
        
    }
    char fin = 'a' +ans;
    cout<<fin;
    

return 0;
}