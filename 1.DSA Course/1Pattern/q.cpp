#include<iostream>
using namespace std;
/*  
****
***
**
*
*/
int main(){
int i = 0 ,n = 4;
while (i<n)
{
    int j = n-i;
    int k =0;
   
    while (k<j)
    {
        cout<<"X";
        k++;
    }
    i++;
    cout<<endl;
    
}

return 0;
}