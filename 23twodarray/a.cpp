#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Linear search in 2d array:
 */
//we need to pass the column size in the parametes to run the program.
bool isPresent(int arr[][3],int a,int row,int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == a)
            {
                return 1;
            }
            
        }
        
    }
    return 0;
}
int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int a = 3;
    if(isPresent(arr,a,3,3)){
        cout<<"found";
    }
return 0;
}