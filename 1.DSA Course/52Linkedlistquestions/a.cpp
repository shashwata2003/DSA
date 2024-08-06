#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Clone a linked list with next and random pointer
    Here we are given linked with a addition property:
    here the structure of the linked list is like:
    Node{
        int data;
        Node* next;
        Node* random;
    }
    the random variable is pointing at a random node of the Linked List our job is to clone the same linked list.
    and return the head of the cloned linked list.

Solution:
Apporach 1:
Time Complexity: O(n2):
Here first we will clone the Linked list without the random pointer. This can be dont easily by running a loop 
using the temp and simulatenously cloneing the node.
After that we can run two loops first will check the random pointer and the next will  place the random pointer
at the correct place

Apporach 2: (optimized)
Here we are going to use a map variable:
step 1:
We will create the singly linked list without the random link
2. then we will create a map<node* , node*> which will link the original linked list with the clone linked list
Now to set the clone->random = mapping[original->random]

This works like if original node 1 points to 3 hence original-> random = 3; 
then 3 is mapped with clone ka 3 hence we set clone->random = map[original ka random]

Apporach 3 : space: O(1) not using map
Here we wil try not to use the map variable. So to do so we need to create in place map between the clone LL and 
the original LL.
Step1: Create the simple clone linked list using the original list
Step2:  Now add the clone list in between the original list hence makeing a zig zag pattern like:
1 1 2 2 3 3 4 4 5 5 . till now we are not dealing with random
step 3: Now to handle the random pointer we will use a temp =  head(original)
temp->next->random(of the clone LL)  = temp -> random->next ;
step 4: revert the changes made in step 2
step 5 return ans.

Now the make the changes in step 2 and step 4 we will use the following method

for step 2:
This is for original node:
Node* nextnode = original->next
original -> next = clonenode
original = nextnode

Node for the clone node:
node* next = clone->next
clone->next = original
clone = next

Now to do step 3:
To revert the step 2:

For the original LL:
original->next = clone->next
original = original ->next

Now for the clone LL:
clone -> next = original ->next
clone = clone->next


  */

// LINK: https://leetcode.com/problems/copy-list-with-random-pointer/description/
// LINK: https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

void insertattail(Node* &head, Node* &tail, int d) {
        Node* temp = new Node(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    //Apporach 2:
    Node* copyRandomList1(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        // step 1: Create the singly linked list
        while (temp != NULL) {
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }
        // step2: Create a map:
        unordered_map<Node*, Node*> oldtonewmap;
        Node* original = head;
        Node* clone = clonehead;
        while(original!=NULL && clone!=NULL){
            oldtonewmap[original] = clone;
            original = original->next;
            clone = clone->next;
        }
        //step3: set random:
        original = head;
        clone = clonehead;
        while(original != NULL){
            clone->random = oldtonewmap[original->random];
            original = original -> next;
            clone = clone->next;
        }
        return clonehead;
    }
//Apporach 3: Spacecomplexity o(1)
    Node* copyRandomList2(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        // step1: create a normal LL:
        Node* temp = head;
        while (temp != NULL) {
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }
        // step 2: adding the clone list to the original list.
        Node* original = head;
        Node* clone = clonehead;
        while (original != NULL && clone != NULL) {
            Node* next = original->next;
            original->next = clone;
            original = next;

            next = clone->next;
            clone->next = original;
            clone = next;
        }

        // Step 3:To handle the random pointer for the clone
        temp = head;
        while (temp != NULL) {
            if (temp->next != NULL) {
                if (temp->random != NULL) {
                    temp->next->random = temp->random->next;
                }
            }
            temp = temp->next->next;
        }
        // Step 4: Revert step 2:
        original = head;
        clone = clonehead;
        while (original != NULL && clone != NULL) {
            original->next = clone->next;
            original = original->next;
            if (original != NULL) {

                clone->next = original->next;
            }
            clone = clone->next;
        }

        // step 5:
        return clonehead;
    }
int main(){

  return 0;
}