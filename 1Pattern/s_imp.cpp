#include<iostream>
using namespace std;
/* 
   1
  121
 12321
1234321 
 */
int main(){
int n = 4, i =0;

while (i<n)
{
    // print spaces
    int spaces = n-i;
    while (spaces)
    {
        cout<<" ";
        spaces--;
    }
    
// print first triangle
int j = 0;
while (j<=i)
{
    cout<<j;
    j++;
}


// print secound triangle 
int start = i;
while (start)
{
    cout<<start;
    start--;
}
cout<<endl;
i++;

}




return 0;
}