#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Problem statement
You are given a non-empty string S containing no spaces’ and a dictionary of non-empty strings (say the list of words). You are supposed to construct and return all possible sentences after adding spaces in the originally given string ‘S’, such that each word in a sentence exists in the given dictionary.

Note :

The same word in the dictionary can be used multiple times to make sentences.
Assume that the dictionary does not contain duplicate words.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= K <= 100
1 <= | word | <= 16
1 <= | S | <= 13

where |word| is the length of each word in the dictionary and |S| is the length of the string S.

Time Limit: 1 sec
Sample Input 1:
1
6
god is now no where here
godisnowherenowhere
Sample Output 1:
god is no where no where
god is no where now here
god is now here no where
god is now here now here
Explanation to Sample Input 1:
One way to make sentences is to take “god” and append a space, then take “is”  and append space, 
take “now” from the dictionary and take “here” as well. 
Similarly, for other sentences also, we can add space to get other possible sentences. Note that 
we can reuse dictionary words as “no” and “now” are used two times in the same sentence.
Sample Input 2:
1
4
god is no here
godisnowhere
Sample Output 2:
No output to be printed
Explanation to Sample Input 2:
We can not make any sentence because after making “god is no” we will be stuck with “where”. 
There is no way to break “where” further such that we can get any word from the dictionary.

https://leetcode.com/problems/word-break-ii/submissions/1350764448/
*/

vector<string> combine(vector<string> prev, string word) {
    for (int i = 0; i < prev.size(); i++) {
        prev[i] += " " + word;
    }
    return prev;
}

vector<string> solve(unordered_map<string,vector<string>> &mp, unordered_set<string> &dict, string s) {
    if (mp.find(s) != mp.end()) {
        return mp[s];
    }

    vector<string> ans;
    if (dict.find(s) != dict.end()) {
        ans.push_back(s);
    }

    for (int i = 1; i < s.length(); i++) {
        //Splits the string after i 
        string word = s.substr(i);
        if (dict.find(word) != dict.end()) {
            //store the string before i and find the breaks int the remaining string
            string rem = s.substr(0, i);
            vector<string> rembreak = solve(mp, dict, rem);
            vector<string> prev = combine(rembreak, word);
            ans.insert(ans.end(), prev.begin(), prev.end());
        }
    }

    return mp[s] = ans;
}

vector<string> wordBreak(string &s, vector<string> &dictionary) {
    unordered_map<string,vector<string>> mp;
    //Inserted in a set to remove duplicates
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    return solve(mp, dict, s);
}

int main(){

return 0;
}