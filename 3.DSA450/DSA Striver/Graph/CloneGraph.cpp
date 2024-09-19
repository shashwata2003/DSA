#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Clone Graph:

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
 */

Node *cloneGraph(Node *node)
{
    if (!node)
        return nullptr;

    //Map the old nodes to the new ones
    unordered_map<Node *, Node *> mp;
    queue<Node *> q;
    q.push(node);

    Node *head = new Node(node->val);

    // Old src to new src
    mp[node] = head;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        // all the adj
        vector<Node *> neigh = front->neighbors;

        for (Node *neighbor : neigh)
        {
            if (mp.find(neighbor) == mp.end())
            {
                // not in the map hence need to create new 
                Node *temp = new Node(neighbor->val);
                mp[neighbor] = temp;
                q.push(neighbor);
            }
            //Update the neighbor of the current node
            mp[front]->neighbors.push_back(mp[neighbor]);
        }
    }
    // return the src
    return mp[node];
}

int main()
{

    return 0;
}