#include<iostream>
using namespace std;
/*  
1
21
321
4321
*/
int main(){
int n=4,i=0;
int k;
while (i<n)
{
    k=i;// we can also remove this line and directly use a equ. like 
    int j=0;
    while (j<=i)
    {
        //cout<<k+1;
        cout<<i-j+1;// this will print the same pattern 
        k--;
        j++;
    }
    cout<<endl;
    i++;
    
}

return 0;
}