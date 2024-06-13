#include<iostream>
using namespace std;

/* 
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
and 
4 3 2 1
4321
4321
4321
 */

int main(){
    int n=4;
    int i =0;
    // first one
    /*while(i<n){
        int j=0;
        while(j<n){
            cout<<j+1;
            j++;
        }
        cout<<endl;
        i++;
    }*/
    while(i<n){
        int j = 0;
        while(j<n){
            cout<<n-j;// or we ca
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}