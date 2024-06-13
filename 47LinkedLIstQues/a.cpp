#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Detect and Remove Loop
Given a singly linked list, you have to detect the loop and remove the loop from the linked list,
if present. You have to make changes in the given linked list itself and return the updated linked list.
Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number
of nodes in the linked list.
Sample Input:
6 2 // 6 -> total no. of nodes in the LL and 2 -> the last node is pointing to 2 hence creating a loop
1 2 3 4 5 6
Sample Output:
1 2 3 4 5 6
Solution:
Appoarch 1:
Here we will use a map variable in which we have keep the data and a bool value called the visited, if we have
visited that node we mark it as true and if that value comes back we say loop detected.
Space complexity: O(n)
Time Complexity: O(n)   

Apporach 2:
Floyd's cycle detection algo:
Here we will use two pointers fast and slow, the slow pointer will go one step at once and the fast pointer will 
go two steps at a time.
if there is a loop in the linked list then at a point fast == slow then loop true
else if fast == NULL then there is no loop present
Space Complexity: O(1)
Time Complecity:O(n)
Why this works:
So we know that the slow pointer is slower than the fast pointer, now when this two pointer enters the loop, as the 
fast pointer is faster than slow pointer so it eventually catch up to the slow pointer at some time hence causing 
fast == slow.

Apporach 3: To find the starting point of the loop
here first we will run the floyd method to get to the point where slow == fast then
2. move slow = head and let both fast and start move at the pace of 1 each
3. now where ever fast == slow will be the point where the loop starts.

Apporach 4: Removing the LOOP 
We will make the last pointer pointing to the starting node to point at the NULL making it without any loops
 */
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Insert at the head
void insertLL(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*,bool> Visited;
    Node* temp = head;
    while (temp!=NULL)
    {
        if(Visited[temp] == true){
            return true;
        }
        Visited[temp] = true;
        temp = temp->next;
    }
    return false;
    
}

Node* returnloopstart(Node* & head){
    if(head == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    Node* intersection = NULL;
    while (slow!=NULL && fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        if(slow == fast){
            intersection = slow;
            break;
        }
    }
    if(intersection == NULL){
        return NULL;
    }
    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

bool floydloopdetection(Node* &head){
    if(head == NULL){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && slow!= NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void removeLoop(Node* head){
    if(head == NULL){
        return;
    }
    Node * startofloop = returnloopstart(head);
    Node* temp = startofloop;
    while (temp != startofloop){
        temp = temp->next;
    }
    temp->next = NULL;
    
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node* tail = node1;
    insertLL(head, 11);
    insertLL(head, 12);
    insertLL(head, 13);
    insertLL(head, 14);
    tail->next = head->next; // this is to create a loop in the list.
    //printLL(head);
    cout << endl;
    //cout<<detectLoop(head);
    //cout<<floydloopdetection(head);
    Node* ans = returnloopstart(head);
    cout<<ans->data;
    removeLoop(head);
    cout<<endl;
    cout<<floydloopdetection(head);
    return 0;
}