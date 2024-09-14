#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 

 */
 int myAtoi(string s) {
        int n = s.length();
        bool flag = false;
        int ans = 0;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (isspace(s[i])) {
                continue;
            } else if (s[i] == '0') {
                k++;
                continue;
            } else if ((s[i] == '-' || s[i] == '+') && k == 0) {
                flag = (s[i] == '-');
                k++;
            } else if (s[i] >= '1' && s[i] <= '9') {
                int wd = s[i] - '0';
                k++;
                if (ans > INT_MAX / 10 ||
                    (ans == INT_MAX / 10 && s[i] - '0' > 7)) {
                    if (flag == 1)
                        return INT_MIN;
                    else
                        return INT_MAX + 1;
                }
                ans = ans * 10 + wd;
            } else {
                break;
            }
        }
        if (flag) {
            ans = -1 * ans;
        }
        return ans;
    }


class Solution {
public:
    int myAtoi(const string& str) {
        int sign = 1, base = 0, i = 0;
        int n = str.length();
        
        // Skip leading whitespaces
        while (i < n && str[i] == ' ') {
            i++;
        }

        // Handle sign
        if (i < n && (str[i] == '-' || str[i] == '+')) {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert string to integer
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            int digit = str[i] - '0';

            // Check for overflow
            if (base > (numeric_limits<int>::max() - digit) / 10) {
                return (sign == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }

            base = base * 10 + digit;
            i++;
        }

        return base * sign;
    }
};
int main(){

return 0;
}