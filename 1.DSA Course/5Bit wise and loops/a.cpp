#include<iostream>
using namespace std;
/* // Fibonicci series 
0 1 1 2 3 5 8 13
*/
int main(){
int a =0;
int b = 1;
int n=10;

for (int i = 0; i < n; i++)
{
    int sum = a+b;
    cout<< sum <<" "<<endl;
    a = b;
    b = sum; 
}

return 0;
}