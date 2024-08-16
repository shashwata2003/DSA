#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Problem statement
Given two 1-dimensional arrays containing strings of lowercase alphabets, print the elements that are common in both the arrays i.e. the strings that are present in both the arrays.

Note:
An element of one array can be mapped only to one element of the array. For example :

Array 1 = {“ab”, “dc”, “ab”, “ab”}
Array 2 = {“dc”, “ab”, “ab”}

The common elements for the above example will be “dc”, “ab”, and “ab”.

Sample Input 1:
1
3 5
at bat rat
rat bar bat rat to
Sample Output 1:
rat bat
Explanation of the Sample Input 1:
The common elements of both the arrays are “bat” and “rat”. Thus, these two elements are printed in the order in which they appear in the second array.
Sample Input 2:
2
2 2
a b
c d
2 1
coding ninjas
coding
Sample Output 2:
coding
Explanation of Sample Input 2
There are no common elements for the first test case. For the second case, “coding” is the common element.
 */

// Apporach 1:
vector<string> findCommonElements(string arr1[], string arr2[], int n, int m)
{
    // Create map to keep the count of the each string present in the array and increment the count
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }
    vector<string> ans;
    for (int i = 0; i < m; i++)
    {
        // now traverse the other array and try to find the string when u find the same string push it in ans
        // and decrement the count.
        if (mp.find(arr2[i]) != mp.end() && mp[arr2[i]] >= 1)
        {
            mp[arr2[i]]--;
            ans.push_back(arr2[i]);
        }
    }

    return ans;
}

// Apporach 2: Using Trie:

struct Node
{
    Node *links[26];
    bool flag = false;
    int word = 0;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void putKey(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *getKey(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    void usetEnd()
    {
        flag = false;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->putKey(word[i], new Node());
            }
            node = node->getKey(word[i]);
        }
        node->word++;
        node->setEnd();
    }

    bool erase(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->getKey(word[i]);
            }
            else
            {
                return false;
            }
        }

        if (node->isEnd())
        {
            node->word--;
            if (node->word == 0)
            {
                node->usetEnd();
            }
            return true;
        }
        else
            return false;
    }
};

vector<string> findCommonElements(string arr1[], string arr2[], int n, int m)

{
    Trie trie;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        trie.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (trie.erase(arr2[i]))
        {
            ans.push_back(arr2[i]);
        }
    }

    return ans;
}
int main()
{

    return 0;
}