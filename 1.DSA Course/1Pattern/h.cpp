#include<iostream>
using namespace std;
/* 
AAA
BBB
CCC for n = 3
 */
int main(){
int n=4, i=0;
while(i<n){
    int j = 0;
    while(j<n){
        char c = 'A' + i;
        cout<<c;
        j++;
    }
    cout<<endl;
    i++;
}
return 0;
}