#include<iostream>
using namespace std;
/* 
1
2 3
4 5 6
7 8 9 10
 */
int main(){
int i=0,n=4;
int k=1;
while (i<n)
{
    int j=0;
    while(j<=i){
        cout<<k;
        k++;
        j++;
    }
    cout<<endl;
    i++;
}

return 0;
}