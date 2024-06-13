#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Evaluate Reverse Polish Notation(evaluate POst fix expressions)
 */

int postfixeval(string arr) {
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        if (isdigit(arr[i])) {
            st.push(arr[i] - '0');
        } else {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            int val = 0;
            switch (arr[i]) {
                case '+':
                    val = val1 + val2;
                    break;
                case '-':
                    val = val1 - val2;
                    break;
                case '*':
                    val = val1 * val2;
                    break;
                case '/':
                    if (val2 != 0) { 
                        val = val1 / val2;
                    } else {
                        return INT_MAX;
                    }
                    break;
                default:
                    return INT_MAX; 
            }
            st.push(val);
        }
    }
    return st.top();
}

int main(){
    string str = "100 200 + 2 / 5 * 7 +";
    vector<int> arr;
    for (int i = 0; i < str.length(); i++)
    {
        int a = str[i]-'0';
        arr.push_back(a);
    }
    int ans = postfixeval(str);
    cout<<ans;
    
return 0;
}