#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

/*Apporach 1 : Basic TLE:*/
class Solution {
public:
    // Function to find the common prefix length between two numbers
    int commonprefix(int num1, int num2) {
        vector<int> nums1;
        vector<int> nums2;

        // Extract digits of num1 in reverse order
        while (num1) {
            int dig = num1 % 10;
            nums1.push_back(dig);
            num1 /= 10;
        }

        // Extract digits of num2 in reverse order
        while (num2) {
            int dig = num2 % 10;
            nums2.push_back(dig);
            num2 /= 10;
        }

        int cnt = 0;
        int n = nums1.size();
        int m = nums2.size();
        int i = n - 1;  // Start from the most significant digit of num1
        int j = m - 1;  // Start from the most significant digit of num2

        // Compare digits from most significant to least significant
        while (i >= 0 && j >= 0) {
            if (nums1[i] == nums2[j]) {
                cnt++;  // Increment count if digits match
            } else {
                break;  // Break the loop if digits do not match
            }
            i--;
            j--;
        }

        return cnt;  // Return the length of the common prefix
    }

    // Function to find the longest common prefix length among two arrays of numbers
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxlen = 0;

        // Compare each pair of numbers from both arrays
        for (int num1 : arr1) {
            for (int num2 : arr2) {
                int len = commonprefix(num1, num2);  // Get common prefix length
                maxlen = max(maxlen, len);  // Update max length
            }
        }

        return maxlen;  // Return the longest common prefix length found
    }
};


/* Apporach 2: Brute Force No TLE:
1. First take one arr and find all the possible prefix by that array and store it in a set 
2. no check the other array if there is any common number and update the maxlen, if not then remove the last 
dig from the back and check again.
*/
class Solution {
public:
    // Function to find the length of the longest common prefix
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        // Insert all prefixes of numbers from arr1 into the set
        for (int i : arr1) {
            while (i > 0) {  // For each number, insert its prefixes into the set
                st.insert(i);
                i = i / 10;  // Remove the last digit to form a prefix
            }
        }

        int ans = 0;

        // Check for the longest matching prefix in arr2
        for (int i : arr2) {
            while (i > 0) {
                if (st.count(i)) {  // If a prefix of number i from arr2 is found in set
                    // Calculate the number of digits in the prefix (log10(i) + 1)
                    ans = max(ans, static_cast<int>(log10(i) + 1));
                    break;  // Exit the loop as we found the longest prefix for this number
                }
                i = i / 10;  // Remove the last digit to continue checking shorter prefixes
            }
        }

        return ans;
    }
};

/*Apporach 3: Optimal Using Trie*/
class Trie {
public:
    // Inner class representing each node of the Trie
    class TrieNode {
    public:
        char data;                // Character stored in the node
        TrieNode* child[10];      // Array for storing child nodes, index corresponds to digits '0'-'9'
        
        // Constructor to initialize a Trie node with a given character
        TrieNode(char d) {
            this->data = d;
            // Initialize all child pointers to NULL (no children yet)
            for(int i = 0; i < 10; i++) {
                this->child[i] = NULL;
            }
        }
    };

    TrieNode* root;  // Root node of the Trie

    // Constructor to initialize the Trie with a root node
    Trie() {
        root = new TrieNode('/');  // Root initialized with a dummy character
    }

    // Recursive function to insert a number (represented as a string) into the Trie
    void insertUtil(string str, TrieNode* node) {
        // Base case: if the string is empty, return (no more digits to insert)
        f(str.empty()) {
            return;
        }i

        // Calculate the index for the current character (digit) by subtracting '0' from it
        int index = str[0] - '0';
        TrieNode* child;

        // Check if the corresponding child node already exists
        if(node->child[index] != NULL) {
            child = node->child[index];  // If exists, move to that child
        } else {
            child = new TrieNode(str[0]);  // If not, create a new child node for the digit
            node->child[index] = child;    // Link the new node to the current node
        }

        // Recursively insert the remaining digits (substring) into the Trie
        insertUtil(str.substr(1), child);
    }

    // Function to insert a number into the Trie
    void insertNum(int num) {
        // Convert the number to a string and insert it
        string numStr = to_string(num);
        insertUtil(numStr, root);  // Start insertion from the root
    }

    // Function to search for the longest common prefix for a given number in the Trie
    int search(int num) {
        TrieNode* crawl = root;  // Start searching from the root node
        string numStr = to_string(num);  // Convert the number to a string
        int length = 0;  // Length of the common prefix

        // Traverse each digit of the number
        for(char ch : numStr) {
            int idx = ch - '0';  // Calculate index for the current digit
            if(crawl->child[idx]) {
                length++;  // Increment length if the digit matches a Trie node
                crawl = crawl->child[idx];  // Move to the next node (digit)
            } else {
                break;  // Stop if no matching node is found
            }
        }

        return length;  // Return the length of the longest common prefix found
    }
};

class Solution {
public:
    // Function to find the longest common prefix between two arrays of numbers
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;  // Create a Trie object

        // Insert all numbers from the first array (arr1) into the Trie
        for(int i : arr1) {
            trie.insertNum(i);
        }

        int maxlen = 0;  // Variable to store the maximum length of common prefix

        // For each number in the second array (arr2), search for its common prefix in the Trie
        for(int i : arr2) {
            int len = trie.search(i);  // Get the length of the common prefix
            maxlen = max(maxlen, len);  // Update maxlen if the current prefix is longer
        }

        return maxlen;  // Return the maximum length of the common prefix found
    }
};

int main(){

return 0;
}