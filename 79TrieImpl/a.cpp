#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Implementing trie:
1. Class implementation of trie node
2. Implementaion of trie
3. Insertation ts: O(length of word)
4. Searching ts: O(length of word)
5. Removal of word
6. start with (given a prefix) we need to find weather a word exist with given prefix
 */

class TrieNode{
    public:
    char data;
    TrieNode* child[26];
    bool isterminal;
    TrieNode(char c){
        this->data = c;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isterminal = false;
    }
};

class trie{
    public:
    TrieNode* root;
    trie(){
        root = new TrieNode('\0');
    }

    // Inserting in a trie
    void insertutil(string word, TrieNode* root){
        if(word.length() == 0){
            // we are at the last word.
            root->isterminal = true;
            return;
        }
        // assuming all inputs are in caps
        int index = word[0] - 'A';
        TrieNode* child;

        //present in the trie
        if(root->child[index] != NULL){
            // just move forward
            child = root->child[index];
        }else{
            // create a new node
            child = new TrieNode(word[0]);
            root->child[index] = child;
        }

        // now run for rest of the word using recursion
        //substr will return a string without the first letter.
        insertutil(word.substr(1),child);
    }
    void insertword(string word){
        // created a different function because we usuall a signal word is send will inserting a word.
        insertutil(word, root);
    }


    // Searching in a trie:

    bool searchwordutil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            // we have traversed the entire word and check weather the current node is a terminal or not
            return root->isterminal;
        }
        //assuming that all char are caps
        int index = word[0] -'A';
        TrieNode* child;
        if(root->child[index] != NULL){
            // char present in the trie hence move to the next word;
            child = root->child[index];
        }else{
            //char is not present hence return false
            return false;
        }
        // check rest of the words in the string using recursion, sending the word except the first letter.
        return searchwordutil(child,word.substr(1));
    }

    bool searchword(string word){
        return searchwordutil(root, word);
    }

    // start with given a prefix:
    bool startwithutil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            // we have traversed the entire word and check weather the current node is a terminal or not
            return true;
        }
        //assuming that all char are caps
        int index = word[0] -'A';
        TrieNode* child;
        if(root->child[index] != NULL){
            // char present in the trie hence move to the next word;
            child = root->child[index];
        }else{
            //char is not present hence return false
            return false;
        }
        // check rest of the words in the string using recursion, sending the word except the first letter.
        return searchwordutil(child,word.substr(1));
    }

    bool startwith(string prefix){
        return startwithutil(root,prefix);
    }
};

int main(){
    trie *t = new trie;
    t->insertword("ABCD");
    cout<<t->searchword("ABCD");
    cout<<t->startwith("AB");
return 0;
}