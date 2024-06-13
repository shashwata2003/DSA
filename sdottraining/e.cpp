#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
queue using stack:
 */
void push(int d, stack<int> &s1, stack<int> &s2){
    
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(d);
    while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    
}

int popandprint(stack<int> &s1, stack<int> &s2){
    if(s1.empty()){
        return -1;
    }
    int d = s1.top();
    s1.pop();
    return d;
}

int main() {
    int q;
    cin>>q;
    stack<int> s1;
    stack<int> s2;
    for(int i = 0;i<q;i++){
        int t;
        cin>>t;
        if(t == 1){
            int d;
            cin>>d;
            push(d,s1,s2);
        }
        if(t == 2){
            cout<<popandprint(s1,s2)<<endl;;
        }
    }
    return 0;
}