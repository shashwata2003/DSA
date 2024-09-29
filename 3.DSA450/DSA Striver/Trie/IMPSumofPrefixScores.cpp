#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */


/*
The original code was give Memmory limit exceed hence we made some memory saving changes
Iterative Insertion: The insert function is now iterative, avoiding deep recursion and reducing stack usage.
Removed char data: Since the data of the node itself is not being used, this reduces the size of each TrieNode.
Efficient Prefix Search: The search function directly calculates the sum of prefix counts.
  */

class Trie {
public:
    class TrieNode {
    public:
        int cnt;                     // Count of words passing through this node
        TrieNode* child[26];         // Array to store child nodes (for letters 'a'-'z')

        // Constructor to initialize a Trie node
        TrieNode() {
            this->cnt = 0;
            for (int i = 0; i < 26; i++) {
                this->child[i] = NULL;
            }
        }
    };

    TrieNode* root;

    // Constructor to initialize the Trie with a root node
    Trie() {
        root = new TrieNode();  // Initialize root
    }

    // Iterative function to insert a string into the Trie
    void insert(string &str) {
        TrieNode* node = root;

        for (char ch : str) {
            int index = ch - 'a';  // Calculate index for the current character

            // If the child node doesn't exist, create a new one
            if (node->child[index] == NULL) {
                node->child[index] = new TrieNode();
            }

            // Move to the child node and increase the count
            node = node->child[index];
            node->cnt++;
        }
    }

    // Function to search for the sum of prefix scores in the Trie
    int search(string &str) {
        TrieNode* node = root;
        int count = 0;  // Variable to store the sum of prefix scores

        // Traverse each character of the string
        for (char ch : str) {
            int index = ch - 'a';  // Calculate index for the current character
            if (node->child[index] == NULL) {
                break;  // Stop if no matching node is found
            }

            node = node->child[index];
            count += node->cnt;  // Add the count at the current node
        }

        return count;  // Return the sum of the prefix scores
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();  // Initialize the Trie

        // Insert all the words into the Trie
        for (string &str : words) {
            trie->insert(str);
        }

        int n = words.size();
        vector<int> ans(n);

        // Calculate the prefix scores for each word
        for (int i = 0; i < n; i++) {
            ans[i] = trie->search(words[i]);
        }

        return ans;  // Return the vector of prefix scores
    }
};


int main(){

return 0;
}