#include<iostream>
using namespace std;
/* 
   *
  **
 ***
**** */
int main(){
int n =4, i =0;
while (i<n)
{
    int j=0;
    int spaces = n-i-1;
    while (spaces)
    {
        cout<<" ";
        spaces--;
    }
    while (j<=i)
    {
        cout<<"*";
        j++;
    }
    cout<<endl;
    i++;
    
    
}

return 0;
}