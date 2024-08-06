#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Circular tour:
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol 
in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
Solution:
Apporach 1:
Brute force method:
traverse the loop with each element in the stack as a start 
Apporach 2:
1. here we will use a pointer called start pointing to the start of the vector.
2. we need to keep a counter for the bal petrol in a variable called balace which we will add after every iteration
3. now if the bal is -ve that means we cannot move to the next pump hence we need to update the start pointer
4. start pointer will be set to current i + 1, as if we are not able to reach the des from the init point that means
we cannot reach the dist from any point in between the init and the current point hence we move next to it.
5. hence update the start pointer
6. now store thr defecent val. this is the val which -ve in the balance. now we know how much balance we need to 
circle back.
7. hence at the end of the loop def + bal == 0 then it is possible to circle the loop

**** see the video once again****
 */

int findstart(vector<int> petrol, vector<int> distance){
    int bal= 0;
    int def = 0;
    int start = 0;
    for (int i = 0; i < petrol.size(); i++)
    {
        bal =bal+ petrol[i] - distance[i];
        if(bal<0){
            def = def+bal;
            start = i+1;
            bal = 0;
        }
    }

    if(def + bal >=0){
        return start;
    }else{
        return -1;
    }
    
}

int main(){
    vector<int> petrol = {4,6,7,4};
    vector<int> distance = {6,5,3,5};
    int ans  = findstart(petrol,distance);
    cout<<ans<<endl;
return 0;
}