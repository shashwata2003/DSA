#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Median in a stream:
Given a unsorted order for int in a running stream we need to find the median of that arr. 
If the no. of element is even return the avg of the two mid val
else return the median

Running stream meaning that new data can enter the array at any time.

Median is the middle value of a array when sorted in ascending order.

eg:
1,2,3,4
ans : 1,1.5,2,2.5
explaination: Here with every new element we are finding a new median 

Sol:
Apporach 1: using sorting
Here we are given a running array so ,
1. we will sort the array using insertion sort as it will take care of the running elements and handle 
any new elements inserted.
2. next we will find the median, if even : return arr[n/2] + arr[n/2 + 1] / 2 and if odd return arr[n/2]

TS: O(n2)

Apporach 2: using heaps:
Here the major issue is to sort the array in a way that it will accept any new element, apart form that ,
finding the median in a sorted arr is simple and will be done in O(1) time as we have direct formula for it
even no. : Arr(n/2)+ arr[n/2+1]/2
odd no. : arr[n/2]

So here we will divide the entire array using a the median as the center, as we know the array is sorted hence
elements on the left will be less than M and the elements on the right of M will be greather than M
using this we can tell weather the array is even or odd
case 1: both left and right same size hence even
case 2: left = n+1 and right = n hence odd
case 3 left = n and right = n+1 hence odd.

also we will insert all the elements of left in max heap and the elements of right in the min heap 
so that the top of both heaps will give the centre elements.

here we are going to use a signum function: which return 
1. 0 when both are equal hence even
2. 1 when left > right
3. -1 vise versa

for
case 1 : take the avg of both the heaps and return the mean. (right == left)
case 2: the minheap.top will be the ans (right> left)
case 3: the median will be maxheap.top (left > right)


Now we will compare sizes of both left and the right half of the array using signum funtion
for case 0: check the the right place to place the new element and place it using the new size of the min and
max heap

for case 1: where left is n+1 and right is n when element is < m we need to push it in left which will make it 
2 difference which we dont want hence we will move a ele form left to righ hence make both left and right equal
hence inplememnting case 2.

for case -1: we will do the same as case 1 and move a element form larger side to the smaller side and 
then push to make both side equal.


TS: O(Nlogn)
SP:
*/

int signum(int a , int b) {
    if (a == b) {
        return 0;
    } else if (a > b) {
        return 1;
    } else {
        return -1;
    }
}

// right = minheap and left = maxheap
void calmedian(int element, int &median, priority_queue<int> &maxheap,
               priority_queue<int, vector<int>, greater<int>> &minheap) {
    switch (signum(maxheap.size(), minheap.size())) {
    case 0:
    //even elements in the arr (as left == right)
        if (element > median) {
            minheap.push(element);
            //we are directly updating median as after pushing the new element the arr becomes odd
            median = minheap.top();
        } else {
            maxheap.push(element);
            median = maxheap.top();
        }
        break;
    case 1:
     //odd elements in the arr (as left > right) 
        if (element > median) {
            minheap.push(element);
            // after push  n+1 n+1 evem
            median = (maxheap.top() + minheap.top()) / 2;
        } else {
            //we are pushing a element form left to right to balance to tree as currly left is n+1 
            // and addingone more element will make it a difference of 2 element which we dont want 
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        break;
    case -1:
    //odd elements in the arr (as left > right)
        if (element > median) {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        } else {
            maxheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        break;
    }
}

vector<int> findmedian(vector<int> arr, int n) {
    int median = -1;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        calmedian(arr[i], median, maxheap, minheap);
        ans.push_back(median);
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    vector<int> ans = findmedian(arr, n);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}