#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
LRU Cache:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add 
the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


APporach
We are going to use a linked list and map to implement this:
two pointer for LL: head 0,0 and tail: 0,0
we add a new node after head which significes recented use node:
The least recently used node will the one after the tail.
Hence we remove form tail and we insert at head

for get function:
we will see if we have the key in the hashmap if so we return the value else -1
when we find the key we need to make it as recently used hence we will delete that node and push it again 
in the LL after head.

O(N) O(1)
 */

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v){
            this->key = k;
            this->val = v;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

  void insertNode(Node* newNode) {
        // Insert a node after head
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            // Element found
            Node* found = mp[key];
            int res = found->val;
            deleteNode(found);
            Node* newNode = new Node(found->key, found->val);  // Create a new node with the same key and value
            insertNode(newNode);
            mp[key] = newNode;  // Update the map with the new node
            return res;
        }
        return -1; // When not found
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // The key-value pair is present in the map, delete the old reference and add a new one
            Node* existingNode = mp[key];
            deleteNode(existingNode);
            mp.erase(key);
        }
        if (mp.size() == cap) {
            // When full, delete the least recently used element
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }
        Node* newNode = new Node(key, value);
        insertNode(newNode);
        mp[key] = newNode;  // Use the newly created node instead of head->next
    }
};

int main(){

return 0;
}