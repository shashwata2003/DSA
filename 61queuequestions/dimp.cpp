#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
First non-repeating character in a stream:
Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from 
the stream, you have to tell which character has appeared only once in the stream upto that point. 
If there are many characters that have appeared only once, you have to tell which one of them was the first one
to appear. If there is no such character then append '#' to the answer.

Input: A = "aabc"
Output: "a#bb"
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c', 
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.


Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'

Solution:
Here we are going use a unordered_map to keep a count of both char and no. of the occurance. also we are going to
use a queue manage the char.
steps:
1. run a loop till the end of the string
2. store the ith char and add it to the map by increamenting its count to 1.
3. push that ch in the queue
4. now if the count of that ch is once then push it in the ans string else pop it till the queue gets empty
5. also at the end of if the queue is empty that means the char has arrived earlier hence push # in the string 
6. return ans.

 */

string firstnonrepeatingele(string s){
    int len = s.length();
    unordered_map<char,int> count;
    queue<char> q;
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        char ch = s[i];
        //Increase the count of the char.
        count[ch]++;
        //push in the queue
        q.push(ch);
        while (!q.empty())
        {
            if(count[q.front()]>1){
                q.pop();
            }else{
                ans.push_back(ch);
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
    
}

int main(){
    string s = "zz";
    string ans = firstnonrepeatingele(s);
    cout<<ans<<endl;
return 0;
}