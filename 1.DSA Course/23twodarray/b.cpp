#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  Row wise sum :
sum of each of the rows of the 2d matrix
*/
int printcolsum(int arr[][3],int row,int col){
    for (int i = 0; i < col; i++)
    {
        int colsum = 0;
        for (int j = 0; j < row; j++)
        {
            colsum= colsum + arr[j][i];
        }
        cout<<colsum<<" ";
    }
    
}
int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 3; i++)
    { 
        int rowsum = 0;
        for (int j = 0; j < 3; j++)
        {
            rowsum = rowsum+arr[i][j];
        }
        cout<<rowsum<<endl;
    }

    printcolsum(arr,3,3);
    
return 0;
}