#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* https://www.geeksforgeeks.org/container-with-most-water/ */
/* 
Everytime, we are moving our pointer i ahead if height of line at ith index is smaller or j pointer if height of line at jth index is smaller. This means whichever line is smaller, we won’t consider it again, because, this line could be the answer only if the other line is larger than it and at maximum width and to be noticed that this is the time when other line is larger as well as max distance apart. So, not considering it makes sense.

In other words, we are required to pair up every line with that line which is greater than it and at maximum distance apart i.e. 

For example -> 8 5 9 1 10 2 6

here, if 8 has to be in the answer then other line that we choose should be 10 as it is the first line from the end that is at maximum distance apart from 8 and longer than 8. Hence, for 8 to be in the answer, other line should be 10.

Now, Lets assume i at 8 and j at 10. Compare it and move the pointer i to 5.

Now, you may ask, ok, you have moved the pointer i to 5 but can it not happen that 5 could pair up with other lines after 10 as we have neglected those lines by moving j pointer to 10.

So, to be noticed that if 5 would have been in the answer then any line after 10 must be >= 5 and if there is any line after 10 whose height is greater than or equal to 5 then its contribution would surely have been calculated while pointer ‘i’ was at 8.
 */

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int l = 0;
    int r = n - 1;
    int area = 0;

    while (l < r) {
        // Calculate the area with the current left and right pointers
        area = max(area, min(arr[l], arr[r]) * (r - l));

        // Move the pointer pointing to the shorter line
        if (arr[l] < arr[r]) {
            l++;
        } else {
            r--;
        }
    }
    
    cout << area;
    return 0;
}