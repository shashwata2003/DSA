#include<iostream>
using namespace std;
/*  
Three small questions:
- a and b are given find the total count of 1 in both the numbers
*/
int countone(int a ){
    int count = 0;
    while (a!=0)
    {
        int bit = a & 1;
        if(bit == 1){
            count++;
        }
        a=a>>1;
    }
    
    return count;
}

int main(){
int a = 2, b = 3;
cout<<countone(a)+countone(b)<<endl;
return 0;
}