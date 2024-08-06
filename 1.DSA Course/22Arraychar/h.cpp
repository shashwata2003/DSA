#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Permutation in a string:
Given 2 string s1 and s2 we need check weather s2 consist any permutation of s1 in it.
eg: s1 = "ab", s2 = "eidbaooo"
permutation ab,ba and ba is in s2 hence return true.
sol: To solve this question we need to use the char array methond in which we used to store the count of every
char repeating in a 26 size array.
so first we will create such a array for s1 and find the occurance of all the char in s1
next we will start traversing the s2 ina window manner(a window is size of the s1) we will also use another char
array for this and check weather they are equal or not if yes the return 2.
after completing the first window we have to move the window to next we can do that by deleting the first char
adding a new one and againg check weather the two char arr are equal or not.
 */
bool checkEqual(int arr1[26], int arr2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] == arr2[i])
        {
            return true;
        }
        return false;
    }
}

int main()
{
    string s1 = "ab";
    string s2 = "eidboaoo";
    int chararr1[26] = {0};
    // creating the first count arr for s1
    for (int i = 0; i < s1.size(); i++)
    {
        int index = s1[i] - 'a';
        chararr1[index]++;
    }
    // travers s2 in the window manner to find the eqal
    int chararr2[26] = {0};
    int window = s1.length();
    int i = 0;
    // this is for the first window
    while (i < window && i < s2.length())
    {
        int index = s2[i] - 'a';
        chararr2[index]++;
        i++;
    }
    if (checkEqual(chararr1, chararr2))
    {
        cout << true;
    }
    // nw moving teh window:
    while (i < s2.length())
    {
        int index = s2[i] - 'a';
        chararr2[index]++;
        index = s2[i - window] - 'a';
        chararr2[index]--;
        i++;
        if (checkEqual(chararr1, chararr2))
        {
            cout << true;
            break;
        }
    }

    return 0;
}