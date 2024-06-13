#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Implement stack using LInked list
Implemet push pop peek and isempty function of a stack using a Linked List.
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
void insertAtTail(Node *&head, Node *tail, int d)
{
  Node *temp = new Node(d);
  if (head == NULL)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

class Stack {
public:
    Node *top;
    Stack() { // constuctor for the Stack.
        this->top = NULL;
    }

    void push(int data) {
      // creare a new node and point temp -> next = top == NULL and resign the value of top
        Node *temp = new Node(data);
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
        temp->data = data;
        temp->next = top; // top == NULL
        top = temp;
    }

    void pop() {
        Node *temp;
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        } else {
            temp = top;
            top = top->next;
            free(temp);
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    int peek() {
        if (!isEmpty())
            return top->data;
        else {
            cout << "\nStack is empty" << endl;
            return -1; 
        }
    }
    // Print all the elements in the stack.
    void display() {
        Node *temp;
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        } else {
            temp = top;
            while (temp != NULL) {
                cout << temp->data;
                temp = temp->next;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

int main()
{
  Node *head = new Node(-1);
  Node *tail = head;
  Stack* st = new Stack();
  st->push(10);
  st->push(11);
  st->pop();
  cout << st->peek() << endl;
  return 0;
}