#include<iostream>
using namespace std;
/* 
There is a party of N people, where these is only one person(celebrity) is known to everyone and that 
person(celebrity) doesn't know anyone in the party. We can only ask questions like "does A know B?". 
Find the person (celebrity) in minimum number of queries

Comp: O(n)

Given a 4 * 4 matrix we need to find the which person is the celebrity
so we start form the top right cornor of the matrix, in this case it is y = 3 and x = 1
now check for weather x know y or not if yes then increment x else increment y. Run the loop until x<y 
pseudo code:
while(x<y){
    if(matrix[x][y]==1){
        x++;
    }else{
        y--;
    }
}
 */
int main(){
    int n = 4;
    int matrix[n][n]= { {0,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
    int y = n - 1;
   
    int x = 0;
    while (x<y)
    {
        if(matrix[x][y] == 1){
            x++;
        }else{
            y--;
        }
    }
     cout<<y;
return 0;
}