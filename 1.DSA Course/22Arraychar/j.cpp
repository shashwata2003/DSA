#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
String Compression:
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the
input character array chars. Note that group lengths that are 10 or longer will be split into
multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]

Solution:
we are given a vector of chars we need to use this char vector to find the ans.so what we will do is we will run a
loop till char[i] = char[j](let j = i+1) and will i+1<n(size of char). when we get out of the loop we are done
traversing a char hence we will store the countand the char in the vector and continue it
 */
int main()
{
    vector<char> ch = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int i = 0;
    int ansindex = 0;
    while (i < ch.size())
    {
        int j = i + 1;
        while (j < ch.size() && ch[i] == ch[j])
        {
            j++;
        }
        ch[ansindex++] = ch[i];
        int count = j - i;
        if(count>1){
            string ct = to_string(count);
            for (int i = 0; i < ct.size(); i++)
            {
                ch[ansindex++] = ch[i];
            }
            
        }
        i= j;
    }
    cout<<ansindex;

    return 0;
}