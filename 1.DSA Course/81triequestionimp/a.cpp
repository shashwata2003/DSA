#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
You are given a list/array of strings which denotes the contacts that exist in your phone directory.
The search query on a string ‘str’ which is a query string displays all the contacts which are present in
the given directory with the prefix as ‘str’. One special property of the search function is that when a user
searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so
for) are shown after the user enters each character.

It is like google search when we type few words it trys to autocomplete our questions:
eg:
Sample Input 1 :
2 // no. of test cases
5 // lenght of the input of the dictornary
cod coding codding code coly
coding // word need to be seached


Sample Output 1 :
cod coding codding code coly
cod coding codding code coly
cod coding codding code coly
coding
coding
coding
Explanation to Sample Input 1 :
In the first test case,
The suggestions for “c” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestions for “co” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestions for “cod” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestion for “codi” is {“coding”}.
The suggestion for “codin” is {“coding”}.
The suggestion for “coding” is {“coding”}.

Sol:
Apporach 1:
Using trie:
1. First add all the words to the trie
2. we need to maintain two strings called the prefix: which insert the single word to it from the search
word provide 2. last word: it will point to the last word which we are treverse in the given search word.
3. we need to trie pointer which will be used to find the lastword and the a prev pointer to point to the prec
node to the current node
4. staying on the current node we will print all the possible word with the help of the isterminal cond.

TS: O(n*m2)
SP: O(M*N)
 */

class trienode
{
public:
    char data;
    trienode *child[26];
    bool isTerminal;

    trienode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
            this->child[i] = nullptr;
        this->isTerminal = false;
    }
};

class trie
{
public:
    trienode *root;

    trie()
    {
        this->root = new trienode('\0');
    }

    void insertwordutil(trienode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        trienode *child;
        int index = word[0] - 'a';
        if (root->child[index] != nullptr)
        {
            child = root->child[index];
        }
        else
        {
            child = new trienode(word[0]);
            root->child[index] = child;
        }
        insertwordutil(child, word.substr(1));
    }

    void insertword(string word)
    {
        insertwordutil(root, word);
    }

    void printsuggestion(trienode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            trienode *next = curr->child[ch - 'a'];
            if (next != nullptr)
            {
                prefix.push_back(ch);
                printsuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getsuggestion(string str)
    {
        vector<vector<string>> output;
        string prefix = "";
        trienode *prev = root;
        for (int i = 0; i < str.size(); i++)
        {
            char lastch = str[i];
            int index = lastch - 'a';
            trienode *curr = prev->child[index];
            if (curr == nullptr)
            {
                output.push_back({"0"});
                break;
            }
            vector<string> temp;
            prefix.push_back(lastch);
            printsuggestion(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
        while (output.size() < str.length())
        {
            output.push_back({"0"});
        }
        return output;
    }
};

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    trie *root = new trie();
    for (int i = 0; i < n; i++)
    {
        root->insertword(contact[i]);
    }
    return root->getsuggestion(s);
}

int main()
{
    vector<string> arr = {"cod", "coding", "codding", "code", "coly"};
    string str = "coding";
    vector<vector<string>> ans = phonedirectory(arr, str);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}