#include <iostream>
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

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

#include <string>
using namespace std;

class Trie
{
public:
    // TrieNode class representing each node in the Trie
    class TrieNode
    {
    public:
        char data;           // Character data stored in the node
        TrieNode *child[26]; // Array of child pointers for each alphabet letter
        bool isTerminal;     // Boolean to check if the node marks the end of a word

        // Constructor to initialize the TrieNode
        TrieNode(char d)
        {
            this->data = d;
            for (int i = 0; i < 26; i++)
            {
                child[i] = nullptr; // Initialize all child pointers to nullptr
            }
            this->isTerminal = false; // Initially, the node is not a terminal node
        }
    };

    TrieNode *root; // Root node of the Trie

    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode('\0'); // Root node with null character
    }

    /** Inserts a word into the trie. */
    void insertUtil(string word, TrieNode *root, int n)
    {
        // Base case: if length of word is 0, mark current node as terminal
        if (n == 0)
        {
            root->isTerminal = true;
            return;
        }

        TrieNode *child;
        int index = word[0] - 'a'; // Calculate index for the current character

        // If the character is already present in the Trie
        if (root->child[index] != nullptr)
        {
            child = root->child[index];
        }
        else
        {
            // If the character is not present, create a new TrieNode
            child = new TrieNode(word[0]);
            root->child[index] = child;
        }

        // Recursively insert the remaining characters
        insertUtil(word.substr(1), child, n - 1);
    }

    void insert(string word)
    {
        int n = word.length();     // Get the length of the word
        insertUtil(word, root, n); // Call the insert utility function
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(string word, TrieNode *root, int n)
    {
        // Base case: if length of word is 0, check if current node is terminal
        if (n == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a'; // Calculate index for the current character
        TrieNode *child;

        // If the character is present in the Trie
        if (root->child[index] != nullptr)
        {
            child = root->child[index];
        }
        else
        {
            // If the character is not present, return false
            return false;
        }

        // Recursively search for the remaining characters
        return searchUtil(word.substr(1), child, n - 1);
    }

    bool search(string word)
    {
        int n = word.size();              // Get the size of the word
        return searchUtil(word, root, n); // Call the search utility function
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startWithUtil(TrieNode *root, string word)
    {
        // Base case: if length of prefix is 0, return true
        if (word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'a'; // Calculate index for the current character
        TrieNode *child;

        // If the character is present in the Trie
        if (root->child[index] != nullptr)
        {
            child = root->child[index];
        }
        else
        {
            // If the character is not present, return false
            return false;
        }

        // Recursively check for the remaining characters in the prefix
        return startWithUtil(child, word.substr(1));
    }

    bool startsWith(string prefix)
    {
        return startWithUtil(root, prefix); // Call the startsWith utility function
    }
    
    // Returns true if root has no children, else false
    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            if (root->children[i])
                return false;
        return true;
    }

    // Recursive function to delete a key from given Trie
    TrieNode *remove(TrieNode *root, string key, int depth = 0)
    {
        // If tree is empty
        if (!root)
            return NULL;

        // If last character of key is being processed
        if (depth == key.size())
        {

            // This node is no more end of word after
            // removal of given key
            if (root->isEndOfWord)
                root->isEndOfWord = false;

            // If given is not prefix of any other word
            if (isEmpty(root))
            {
                delete (root);
                root = NULL;
            }

            return root;
        }

        // If not last character, recur for the child
        // obtained using ASCII value
        int index = key[depth] - 'a';
        root->children[index] =
            remove(root->children[index], key, depth + 1);

        // If root does not have any child (its only child got
        // deleted), and it is not end of another word.
        if (isEmpty(root) && root->isEndOfWord == false)
        {
            delete (root);
            root = NULL;
        }

        return root;
    }
};

int main()
{
    trie *t = new trie;
    t->insertword("ABCD");
    cout << t->searchword("ABCD");
    cout << t->startwith("AB");
    return 0;
}