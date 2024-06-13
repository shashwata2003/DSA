#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Implement queue using Linked list: */

#include <bits/stdc++.h> 

struct Node {
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

class Queue {
public:
    Node* qfront;
    Node* rear;

    Queue() {
        qfront = NULL;
        rear = NULL;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return qfront == NULL;
    }

    void enqueue(int data) {
        Node* temp = new Node(data);
        if (isEmpty()) {
            qfront = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        } else {
            Node* temp = qfront;
            int ans = qfront->data;
            qfront = qfront->next;
            delete temp;
            if (qfront == NULL) {
                rear = NULL;
            }
            return ans;
        }
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return qfront->data;
    }
};

int main(){

return 0;
}