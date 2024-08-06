#include<iostream>
using namespace std;
/* 
Linear search:

 */

bool search(int arr[],int size,int key){
for (int i = 0; i < size; i++)
{
    if(arr[i] == key){
        return true;
    }
}
return false;
}

int main(){
int arr[5] = {1,2,3,4,5};
int key = 4;
cout<<search(arr,sizeof(arr),key);
return 0;
}