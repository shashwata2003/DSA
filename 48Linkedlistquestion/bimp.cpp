#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Remove Duplicates From an Unsorted Linked List:
Given a unsorted list we need to remove all the duplicates from it
Sample Input:
2
4 2 5 4 2 2 -1
1 2 1 2 2 2 7 7 -1
Sample Output 1 :
4 2 5 -1
1 2 7 -1

Sample Input 2 :
2
3 3 3 3 3 -1
10 20 10 20 30 10 20 30 -1
Sample Output 2 :
3 -1
10 20 30 -1

apporach1:
Here we take the first element and we traverse the entire list with that element if we find a match we delete it
we do this until current == NULl
Time complexity: O(n2)
Space COmplexity: O(n)
apporach 2:
We will sort the given list and the use the removing duplicates in sorted list algorthm here.
Time Complexity: O(nlogn)
Space complexity: O(1)

Apporach 3:
We will create a map called visited using it we will mark all the visted nodes if any of them is true we will delete 
it
TimeComplexity: O(n)
Space Complexity: O(1)
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
    ~Node(){
        this->data;
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

Node* removeduplicatesinunsortedlist1(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* current = head;
    while (current != NULL) {
        Node* runner = current;
        while (runner->next != NULL) {
            if (current->data == runner->next->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }

    return head;
}

Node* removeduplicatesinunsortedlist2(Node* head) {
    if (head == NULL) {
        return head;
    }
    
    map<int, bool> visited;
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (visited.find(current->data) != visited.end()) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            visited[current->data] = true;
            prev = current;
            current = current->next;
        }
    }

    return head;
}

int main()
{
    Node *node1 = new Node(14);
    Node *head = node1;
    Node *tail = node1;
    insertLL(head, 13);
    insertLL(head, 11);
    insertLL(head, 12);
    insertLL(head, 11);
    insertLL(head, 14);
    insertLL(head, 13);
    printLL(head);
    removeduplicatesinunsortedlist1(head);
    cout << endl;
    printLL(head);
    return 0;
}