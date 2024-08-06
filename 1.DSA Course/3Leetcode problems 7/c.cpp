#include<iostream>
#include <math.h>
#include <climits>
using namespace std;
/*  
leet code : power of two 
given n = 16 which is 2 power 4 hence true 
f n = 14 which is not a power of 3 hence false
*/
int main(){
int n = 16;
int i =0;
int flag = 1;
int ans = 1;
while (i<=30)
{
    // we can optimize the code by reuseing the ans and not cal it every time
 
    if(ans == n){
        cout<<"true";
        flag = 0;
    }
    if(ans < INT_MAX/2){
    ans = ans * 2;
    }
    i++;
}
if(flag == 1){
   
        cout<<"false";
    
}


return 0;
}