#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Largest Row Sum:
Among all the sum of the row find the largest of all.
 */
int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int maxi = -1;
    int rowindex = -1;
    for (int i = 0; i < 3; i++)
    {
        int rowsum = 0;
        for (int j = 0; j < 3; j++)
        {
            rowsum = rowsum + arr[i][j];
        }
        if (rowsum>maxi)
        {
            maxi = rowsum;
            rowindex  = i;
        }
    }
    cout<<maxi<<endl;
    cout<<rowindex<<endl;
    
return 0;
}