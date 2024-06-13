#include<iostream>
using namespace std;
/* Swap Alternate:
given a array of size n eg {1,2,3,4}
swap the array like this {2,1,4,3}
 */
void swaparrays(int arr[],int size){
    for (int i = 0; i < size; i=i+2)
    {
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    }
    
}

int main(){
int arr1[6] = {1,2,3,4,5,6};
int arr2[5] = {1,2,3,4,5};
swaparrays(arr2,sizeof(arr2)/sizeof(int));
for (int i = 0; i < sizeof(arr2)/sizeof(int); i++)
{
    cout<<arr2[i]<<" ";
}

return 0;
}