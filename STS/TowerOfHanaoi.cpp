#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Tower of Hanoi problem: Given three dics and three point we need to move all the three disk in the same order 
as the source to the desitination with the help of aux pole.
We need to find the minimum no. of movements to take place to move all the dics
 */

int TOH(int n, char start, char aux, char des,int count){
    count++;
    if(n==1){
        cout<<"Move disk - "<<n<<" from "<<start<<" to "<<des<<endl;
        return count;
    }
    TOH(n-1,start,des,aux,count);
    cout<<"Move disk - "<<n<<" from "<<start<<" to "<<des<<endl;
    TOH(n-1,aux,start,des,count);
    return count;
}

int main(){
int n = 3;
int count = 0;
int ans = TOH(n,'A','B','C',count);
cout<<ans;
return 0;
}