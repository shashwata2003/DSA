#include<iostream>
using namespace std;
/* 
use of exit()
 */
int main(){
    int num=1;
while (1)
{
    
    switch (num)
    {
    case 1:
        cout<<"one";
        exit(0);
        break;
        
    
    default:
        break;
    }
}

return 0;
}