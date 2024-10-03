/*

Q12:
Problem Statement



Given a sentence, the task is to remove spaces from the sentence and rewrite it in camel case. It is a style of writing where we don’t have spaces and all words begin with capital letters.



Examples



Input: I got to intern at iamNeo

Output: IGotToInternAtIamNeo



Input: Here comes the garden

Output: HereComesTheGarden

Input format :
The input consists of a string s containing lowercase and uppercase English letters and spaces.

Output format :
The output prints the modified string where each word in the string starts with an uppercase letter, and all spaces are removed.



Refer to the sample output for formatting specifications.

Code constraints :
The maximum length of the input string is 300.

Sample test cases :
Input 1 :
I got to intern at iamNeo
Output 1 :
IGotToInternAtIamNeo
Input 2 :
Here comes the garden
Output 2 :
HereComesTheGarden
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
string newstring(string str){
    string ans = "";
    int n = str.length();
    bool cap = false;
    for (int i = 0; i < n; i++)
    {
        if(str[i] == ' '){
            cap = true;
        }else{
            if(cap || ans.empty()){
                ans += toupper(str[i]);
                cap = false;
            }else{
                ans += tolower(str[i]);
            }
        }
    }
    return ans;
}

int main(){
    string str;
    getline(cin, str);
    cout<<newstring(str);
return 0;
}