#include<iostream>
using namespace std;
/* 
Reverse an Array
 */


int Reverse(int arr[],int size){
int start = 0;
int end = size-1;
while (start<=end)
{
    swap(arr[start],arr[end]);
    start++;
    end--;
}

}
int main(){
int arr[5] = {1,2,3,4,5};
Reverse(arr,sizeof(arr)/sizeof(int));

for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
{
    cout<<arr[i]<<" ";
}


return 0;
}