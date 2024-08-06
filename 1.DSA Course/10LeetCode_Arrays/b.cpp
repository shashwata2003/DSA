#include<iostream>
using namespace std;
/* 
CodeStudio: Find Unique https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbVVBM0lZMUhYQld0QThXU28tbVQxdkR3VFFZUXxBQ3Jtc0tuT08xenlxN3RJX2JlS2FCS0t4eHhLdklNaHdMLXRtbWV3LWVFVlU0cnlyVG5RUzNDVlRFeEhabnFKMWRmLUVsUENnS1NFYnR1bjBFUHRLb0JfYWJFRW53X1EyRkkzcVBZYmpTbTRPeXNfLW4zRm41Yw&q=https%3A%2F%2Fbit.ly%2F3y01Zdu&v=oVa8DfUDKTw
Given a array of n = 2m+ 1(odd no.s) 
M no's are appearing twice and one number is appearing once 
find that single appearing no.
eg: m = 2 hence n = 5 let array be [1,2,1,2,3]
here the answer will be 3 as 1&2 appears twice

sol: We can use XOR bit wise operator to find the single digit element
like 1^2^1^2^3 = 3
 */
int main(){
int arr[5] = {1,2,1,2,3};
int size = sizeof(arr)/sizeof(int);
int ans=0;
for (int i = 0; i < size; i++)
{
    ans = ans^arr[i];
}
cout<<ans;
return 0;
}