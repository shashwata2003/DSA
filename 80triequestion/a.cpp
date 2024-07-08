#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Longest Common prefix:
You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among
 all these strings. If there is no common prefix, you have to return an empty string.

A prefix of a string can be defined as a substring obtained after removing some or all characters from the 
end of the string.

Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings.
 Hence, the answer is “cod”.

Sample Input 1:
2 // no. of test cases
4 // n
coding codezen codingninja coder
3
night ninja nil 
Sample Output 1:
cod
ni

Sol:
Apporach 1:(Brute Force):
1. pick up the first letter from the first string and compare it with the other strings first letter
2. if it matchs then we add it to the ans vector.
3. return the ans.

TS: O(M*N)
SP: O(M)

Apporach 2: using trie
Here we will create   trie for all the string in the input 
and we will check if that particular node has 1 child or not, if so we will add that data in the ans
and continue doing so till the condition of 1 child breaks

TS: O(M*N)
SP: O(M*N)

 */


// Apporach 1: Brute force
string findlongestprefixappr1(vector<string> arr, int n){
    string ans = "";

    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool ismatch = true;
        for (int j = 1; j < n; j++)
        {
            // checking the rest  of the string with the first element of the first string.
            // not a match with the ch and also the size of the word should be less than i
            if(arr[j].size() <= i  || ch != arr[j][i]){
                ismatch = false;
                break;
            }
        }
        if(ismatch){
            ans.push_back(ch);
        }else{
            break;
        }
        
    }
    return ans;
    
}


/// Apporach 2: using trie
class trienode {
public:
    char data;
    trienode* child[26];
    int childcount;
    bool isterminal;

    trienode(char d) {
        this->data = d;
        for (int i = 0; i < 26; i++) {
            this->child[i] = NULL;
        }
        this->childcount = 0;
        this->isterminal = false;
    }
};

class Trie {
public:
    trienode* root;
    Trie() {
        this->root = new trienode('\0');
    }

    void insertwordutil(trienode* root, string word) {
        if (word.length() == 0) {
            root->isterminal = true;
            return;
        }
        trienode* child;
        int index = word[0] - 'a';
        // present in the trie
        if (root->child[index] != NULL) {
            child = root->child[index];
        } else {
            child = new trienode(word[0]);
            root->childcount++;
            root->child[index] = child;
        }

        // recursion:
        insertwordutil(child, word.substr(1));
    }

    void insertword(string word) {
        insertwordutil(root, word);
    }

    void findlcp(string &first, string &ans) {
        trienode* current = root;
        for (int i = 0; i < first.length(); i++) {
            char ch = first[i];
            if (current->childcount == 1) {
                // move ahead;
                ans.push_back(ch);
                int index = ch - 'a';
                current = current->child[index];
            } else {
                break;
            }

            if (current->isterminal) {
                break;
            }
        }
    }
};

string findlongestprefixappr2(vector<string> arr, int n) {
    Trie roottree;
    for (int i = 0; i < n; i++) {
        roottree.insertword(arr[i]);
    }
    string ans = "";
    string first = arr[0];
    roottree.findlcp(first, ans);
    return ans;
}

int main() {
    vector<string> arr = {"coding", "codezen", "codingninja", "coder"};
    vector<string> arr1 = {"night", "ninja", "nil"};
    int n = arr.size();
    string ans = findlongestprefixappr2(arr, n);
    cout << ans;
    return 0;
}