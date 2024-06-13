#include<iostream>
using namespace std;
/* 
123
456
789 */
int main(){
    int n = 3;
    int i =0;
    int k = 1;
while (i<n)
{
    int j=0;
    while (j<n)
    {
        cout<<k;
        k++;
        j++;
    }
    cout<<endl;
    i++;
    
}

return 0;
}