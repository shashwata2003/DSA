#include <iostream>
#include <vector>

using namespace std;

/*
You are tasked with implementing a program that manages a group of customers in a store. The store maintains a waiting list of customers in a singly linked list. A unique integer ID represents each customer.



Write a program that adds customers one by one at the front of the line, removes the first customer from the front, and displays the same.



Example:



Input:

4

10 20 30 40



Output:

30 20 10 



Explanation:

The linked list is constructed as follows:

Insert 10: 10 -> nullptr

Insert 20: 20 -> 10 -> nullptr

Insert 30: 30 -> 20 -> 10 -> nullptr

Insert 40: 40 -> 30 -> 20 -> 10 -> nullptr

Remove the first customer (40):  30 -> 20 -> 10 -> nullptr. So 30 20 10 is printed as output.
*/

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node*& head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void deleteFromHead(Node*& head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void printLL(Node* head, vector<int> &ans){
    Node* temp = head;
    while(temp){
        ans.push_back(temp->data);
        temp = temp->next;
    }
}

int main(){
    int n;
    cin >> n;
    Node* head = NULL;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        insertAtHead(head, d);
    }
    deleteFromHead(head);
    vector<int> ans;
    printLL(head, ans);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}