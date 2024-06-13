#include<iostream>
using namespace std;
/* 
1
23
345
4567
 */
int main(){
int n=4, i =0;
int k;
while (i<n)
{
    int j=0;
    k=i;// we can do without this line also 
    while (j<=i)
    {
        //cout<<k+1;
        cout<<i+j+1; // using this eq we can eliment the k=i wali line 
        k++;
        j++;
    }
    i++;
    cout<<endl;

}

return 0;
}