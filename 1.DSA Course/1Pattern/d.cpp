#include<iostream>
using namespace std;
/* 
1
22
333
4444 for n = 4
 */
int main(){
int n =4;
int i = 0;
while (i<n)
{
    int j=0;
    while(j<=i){
        cout<<i+1;
        j++;
    }
    cout<<endl;
    i++;
}

return 0;
}