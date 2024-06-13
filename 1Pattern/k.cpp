#include<iostream>
using namespace std;
/*  
ABC
BCD
CDE
*/
int main(){
int n = 3, i =0;

while (i<n) 
{
    char c='A';
    c=c+i; // we can do this by updating the formula we used for the no. pattern which was like this one one
    // that is i+j-1 .But to map this to the alphabets we will use 'A'+i+j-2
    int j =0 ;
    while (j<n)
    {
       cout<<c;
       c++;
       j++;
    }
    cout<<endl;
    i++;
    
}

return 0;
}