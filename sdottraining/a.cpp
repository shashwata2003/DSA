#include <iostream>

using namespace std;

/*1. Merger two sorted Linked List
2. Print a 2D matrix in the spiral pattern
3. Reverse K elements */

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

void insertathead(Node *&head, int d)
{
  Node *temp = new Node(d);
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
}

void insertatend(Node *&tail, int d)
{
  Node *temp = new Node(d);
  if (tail == nullptr)
  {
    tail = temp;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

Node *
MergeSortedList(Node *&head1, Node *&head2)
{
  if (head1 == NULL)
  {
    return head2;
  }
  if (head2 == NULL)
  {
    return head1;
  }
  Node *l1 = head1;
  Node *l2 = head2;
  Node *ans = NULL;
  if (l1->data <= l2->data)
  {
    ans = l1;
    l1 = l1->next;
    ans->next = MergeSortedList(l1, l2);
  }
  else
  {
    ans = l2;
    l2 = l2->next;
    ans->next = MergeSortedList(l1, l2);
  }
  return ans;
}

Node *
reverseKElement(Node *&head, int k)
{
  if (head == NULL)
  {
    return head;
  }
  Node *current = head;
  Node *prev = NULL;
  Node *forward = NULL;
  int count = 0;
  while (current != NULL && count < k)
  {
    forward = current->next;
    current->next = prev;
    prev = current;
    current = forward;
    count++;
  }
  if (forward != NULL)
  {
    head->next = reverseKElement(forward, k);
  }
  return prev;
}

void printSpiral(int arr[][4], int n, int m)
{
  int firstrow = 0;
  int lastrow = n - 1;
  int firstcol = 0;
  int lastcol = m - 1;
  while (firstrow <= lastrow && firstcol <= lastcol)
  {
    // print first row
    for (int i = firstcol; i <= lastcol; i++)
    {
      cout << arr[firstrow][i] << " ";
    }
    firstrow++;
    // print last col:
    for (int i = firstrow; i <= lastrow; i++)
    {
      cout << arr[i][lastcol] << " ";
    }
    lastcol--;
    // print lastrow
    for (int i = lastcol; i >= firstcol; i--)
    {
      cout << arr[lastrow][i] << " ";
    }
    lastrow--;
    // print lastcol:
    for (int i = lastrow; i >= firstrow; i--)
    {
      cout << arr[i][firstcol] << " ";
    }
    firstcol++;
  }
}

int main()
{
  Node *node1 = new Node(18);
  Node *head1 = node1;
  insertathead(head1, 16);
  insertathead(head1, 13);
  insertathead(head1, 12);
  insertathead(head1, 11);
  // printLL (head1);
  Node *node2 = new Node(19);
  Node *head2 = node2;
  cout << endl;
  insertathead(head2, 17);
  insertathead(head2, 15);
  insertathead(head2, 13);
  insertathead(head2, 11);
  // printLL (head2);
  // Node *ans = MergeSortedList (head1, head2);
  printLL(head1);

  cout << endl;
  head1 = reverseKElement(head1, 3);
  printLL(head1);
  Node *node = new Node(2);
  Node *tail = node;
  Node *head = node;
  insertatend(tail, 1);
  insertatend(tail, 6);
  insertatend(tail, 4);
  insertatend(tail, 8);
  int m = 4, n = 4;
  int arr[m][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  // printSpiral(arr,m,n);
  return 0;
}
