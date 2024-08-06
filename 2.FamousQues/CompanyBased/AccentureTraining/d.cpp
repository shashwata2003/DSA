#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Shopkeeper Problem:
Given that the a transaction can only be done in the denomination of 30 60 120
-> each customer can only buy stuff of 30 rs
Gievn array of tranction tell weather it will be successful or not.
 */
int main(){
    vector<int> arr = {30,60};
    int c30 = 0, c60 = 0, c120 = 0;
    for (int  i = 0; i < arr.size(); i++)
    {
        if(arr[i] == 30){
            c30++;
        }
        else if(arr[i] == 60){
            c60++;
            if(c30>0){
                c30--;
            }else{
                cout<<"failed"<<endl;
            }
            
        }
        else if(arr[i] == 120){
            c120++;
            if(c30>3){
                c30 =c30-3;
            }else if(c60>1 && c30>1){
                c30--;
                c60--;
            }else{
                cout<<"Failed";
            }
        }
    }
    cout<<"Success"<<endl;
    
return 0;
}