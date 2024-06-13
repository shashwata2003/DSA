#include<iostream>
using namespace std;
/* 
find the min and max of the array */

int getMin(int arr[]){
    int min = INT_MAX;
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; i++)
    {
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
    
}
int main(){
int arr[4]={1,2,3,4};
cout<<getMin(arr);
return 0;
}