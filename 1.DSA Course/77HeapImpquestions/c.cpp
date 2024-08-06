#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given a string “S”. Your task is to rearrange the characters of a string “S”, such that it does not 
contain any two adjacent characters which are the same.

If it is possible to rearrange the string “S”, then print any possible arrangement. else, print “not possible”
 without quotes.

For Example:

For a string  “qaacde”, This string has two same adjacent characters.
So, one possible way to rearrange the string is “qacade”. Now, this string does not have two adjacent 
characters that are the same. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10    
0 <= |S| <= 10^5 

Time Limit: 1 sec
Sample Input 1 :
2 
coding
abaab
Sample Output 1 :
Yes
Yes
Explanation :
For the first test case, the given string is “coding”. This string does not have two adjacent characters 
that are the same. So if we return “coding", then we will get an output as “Yes”.

For the second test case, the given string is “abaab”. This string has two adjacent characters that are the
 same i.e. abaab,  So we can rearrange the string as “ababa”.Hence we return “ababa”, then we will get an output as "Yes”.
Sample Input 2 :
1
bbbbbb
Sample Output 2 :
Yes
Explanation :
For the first test case, the given string is “bbbbbb”. No matter how you rearrange characters of string , 
it will always remain the same as bbbbbb.So we return “not possible” as an answer, then we will get an output 
as ‘Yes”.

Sol:
Steps:
Build a Priority_queue or max_heap, pq that stores characters with their frequencies. 
    Priority_queue or max_heap is built on the basis of the frequency of character. 
    Create a temporary Key that will be used as the previously visited element (the previous element in the
    resultant string. Initialize it { char = ‘#’ , freq = ‘-1’ } 
While pq is not empty. 
    Pop an element and add it to the result. 
    Decrease the frequency of the popped element by ‘1’ 
    Push the previous element back into the priority_queue if its frequency is greater than zero. 
    Make the current element as the previous element for the next iteration. 
If the length of the resultant string and the original string is not equal, then print “not possible”, else print the resultant string.
 */

class Node {
public:
    char ch;
    int freq;
    Node(char ch, int f) {
        this->ch = ch;
        this->freq = f;
    }
};

// Comparator class for the priority queue
class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq < b->freq;
    }
};

string reArrangeString(string &s) {
    priority_queue<Node*, vector<Node*>, compare> maxheap;
    int n = s.length();
    vector<int> count(26, 0);
    
    // Count frequencies of each character
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    // Push nodes into the max-heap
    for (char i = 'a'; i <= 'z'; i++) {
        int val = i - 'a';
        if (count[val] > 0) {
            Node* temp = new Node(i, count[val]);
            maxheap.push(temp);
        }
    }

    string result = "";
    Node* prev = new Node('#', -1); // Placeholder for the previous character

    while (!maxheap.empty()) {
        Node* top = maxheap.top();
        maxheap.pop();
        result += top->ch;

        // Push the previous character back if its frequency is still positive
        if (prev->freq > 0) {
            maxheap.push(prev);
        }

        // Update the frequency of the current character and set it as the previous character
        top->freq--;
        prev = top;
    }

    // Clean up the last node if it was dynamically allocated
    if (prev->ch != '#') {
        delete prev;
    }

    // Check if the rearrangement was successful
    if (result.length() == n) {
        return result;
    } else {
        return "not possible";
    }
}
int main() {
    string s = "aabbcc";
    string result = reArrangeString(s);
    if (result == "Not Possible") {
        cout << result << endl;
    } else {
        cout << "Rearranged string: " << result << endl;
    }
    return 0;
}