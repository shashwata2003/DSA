/*
Q1:
We have given Ankit an input string, s, and a target string, t. The strings will have lengths - lenS, and lenT respectively. He has to find the smallest subset in the input string that contains all the elements in the target. If he fails to do so, he must return null.



Example1



Input:

sajkfhk

hjk



Output:

Smallest subset: jkfh



Explanation:

Since the target value is hjk, the smallest subset containing these characters is jkfh.



Example2



Input:

sajkab

hjk



Output:

Smallest subset: null



Explanation:

﻿Since the target value is hjk, the smallest subset does not contain all these elements. Thus, it returns null.

Input format :
The first line of input consists of a string, S.

The second line of input consists of a string, T.

Output format :
The output displays "Smallest subset: " followed by the smallest subset.



Refer to the sample output for formatting specifications.

Code constraints :
The strings contain lowercase characters.

1 ≤ lenS ≤ 20

1 ≤ lenT ≤ 10

Sample test cases :
Input 1 :
sajkfhk
hjk
Output 1 :
Smallest subset: jkfh
Input 2 :
sajkab
hjk
Output 2 :
Smallest subset: null

Q2:
Problem Statement



Given an array of strings strs, group the anagrams together. You can return the answer in any order.



An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example:

Input: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

Output: [["bat"],["nat", "tan"],["ate", "eat", "tea"]]                            

Input format :
The first line consists of an integer n, representing the number of strings.

The second line consists of n space-separated strings, represented as strs.

Output format :
The output prints grouped anagrams, where each group is present in a separate line, and inside each group, the anagrams are separated by a space.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ strs.length (n) ≤ 20

1 ≤ strs[i].length ≤ 30

strs[i] consists of lowercase English letters.

Sample test cases :
Input 1 :
6
eat tea tan ate nat bat
Output 1 :
bat 
tan nat 
eat tea ate 
Input 2 :
2
ab nj
Output 2 :
nj 
ab 
Input 3 :
3
abc cba cab
Output 3 :
abc cba cab 

Q3:
ut 2 :
Second string: iaam
The strings do not match
Input 3 :
i*mn?o
iaamneo
Output 3 :
Second string: iaamneo
The strings match
Input 4 :
a?b?c?d?e?f?gh
axbxcydzefffgh
Output 4 :
Second string: axbxcydzefffgh
The strings match
Input 5 :
A*c
ac
Output 5 :
Second string: ac
The strings do not mat

Q4:
Problem Statement



You are given a string. Using a recursive function, you have to obtain different combinations of the string or in other words permutations of the given string and all the sub-strings in alphabetical order.



Note: The characters within the sub-string can be repeated.



Example



Input:

ABC



﻿Output:

AAA AAB AAC ABA ABB ABC ACA ACB ACC BAA BAB BAC BBA BBB BBC BCA BCB BCC CAA CAB CAC CBA CBB CBC CCA CCB CCC 

Input format :
The input consists of a string.

Output format :
The output prints the list of permuted strings, separated by a space.



Refer to the sample output for formatting specifications.

Code constraints :
The input consists of uppercase characters and a maximum length of 4 characters.

Sample test cases :
Input 1 :
BD
Output 1 :
BB BD DB DD 
Input 2 :
ABC
Output 2 :
AAA AAB AAC ABA ABB ABC 

Q5:
Problem Statement



Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.



Example 1:

Input: s = "bcabc"

Output: "abc"



Example 2:

Input: s = "cbacdcbc"

Output: "acdb"

Input format :
The first line of input consists of a string s, representing the input string.

The second line consists of an integer n, indicating the number of words in the dictionary.

The next line consists of n space-separated strings representing the words of the dictionary.

Output format :
If the input string can be segmented into words from the dictionary, output "true".

If the input string cannot be segmented into words from the dictionary, output "false".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ s.length ≤ 100

s consists of only lowercase English letters.

Sample test cases :
Input 1 :
bcabc
Output 1 :
abc
Input 2 :
cbacdcbc
Output 2 :
acdb

Q6:
Problem Statement



Jin is working on a string manipulation problem. He needs to replace all occurrences of a specified pattern within a given word with a specified character. 



Write a program to help Jin achieve this task efficiently.



Example



Input:

ABCABCXABCabc

ABC

#

Output:

##X#abc

Explanation:

After replacing occurrences of the pattern ABC with #, the resultant string becomes ##X#abc.

Input format :
The first line of input consists of the original word as a string.

The second line consists of the pattern as a string.

The third line consists of the character that will replace occurrences of the pattern.

Output format :
The output prints a string representing the modified word after replacing occurrences of the pattern with the specified character.



Refer to the sample output for formatting specifications.

Code constraints :
The length of the word is at most 200 characters.

The strings are case sensitive.

Sample test cases :
Input 1 :
ABCABCXABCabc
ABC
#
Output 1 :
##X#abc
Input 2 :
abxgyuabx
abx
5
Output 2 :
5gyu5
Input 3 :
ABXVYUABXE
ABX
C
Output 3 :
CVYUCE

Q7:
Problem Statement



Form the minimum number from the given sequence:



Given a pattern containing only I's and D's. I for increasing, and D for decreasing. Device an algorithm to print the minimum number following that pattern. Digits from 1–9 and digits can't repeat.



Examples: 





Input format :
The input consists of a single line string input consisting of characters 'I' and 'D' only, where:

'I' stands for "Increasing".
'D' stands for "Decreasing".
Output format :
The output displays a single line string representing the minimum number that can be formed following the given sequence of 'I's and 'D's.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ length of string ≤ 8

Sample test cases :
Input 1 :
ID
Output 1 :
132
Input 2 :
D
Output 2 :
21
Input 3 :
IDDD
Output 3 :
15432

Q8:

Problem Statement



Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"

Output: 3

Explanation: The answer is "abc", with a length of 3.



Example 2:

Input: s = "bbbbb"

Output: 1

Explanation: The answer is "b", with a length of 1.     



Example 3:

Input: s = "pwwkew"

Output: 3

Explanation: The answer is "wke", with a length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.                                                                                                        

Input format :
The input consists of a string s.

Output format :
The output prints the length of the longest substring without repeating characters.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ s.length ≤ 100

Sample test cases :
Input 1 :
abcabcbb
Output 1 :
3
Input 2 :
bbbb
Output 2 :
1
Input 3 :
pwwkew
Output 3 :
3

Q9:
Problem Statement



Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.



Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "applepenapple", wordDict = ["apple","pen"]

Output: true

Explanation: Return true because "applepenapple" can be segmented as "apple pen apple". Note that you are allowed to reuse a dictionary word.



Example 2:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]

Output: false

Input format :
The first line of input consists of a string s, representing the input string.

The second line consists of an integer n, indicating the number of words in the dictionary.

The next line consists of n space-separated strings representing the words of the dictionary.

Output format :
If the input string can be segmented into words from the dictionary, output "true".

If the input string cannot be segmented into words from the dictionary, output "false".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ s.length ≤ 100

1 ≤ wordDict.length ≤ 10

1 ≤ wordDict[i].length ≤ 100

s and wordDict[i] consist of only lowercase English letters.

All the strings of wordDict are unique.

Sample test cases :
Input 1 :
applepenapple
2
apple pen
Output 1 :
true
Input 2 :
catsandog
5
cats dog sand and cat
Output 2 :
false

Q10:
Problem Statement



Given two strings, s, and t, the task is to find the maximum length of some prefix of the string s that occurs in string t as a subsequence.



Example



Input: 

s = "digger"

t = "biggerdiagram"

Output: 

3

Explanation: 

Prefix "dig" of s is the longest subsequence in t.

Input format :
The first line input consists of a string, representing s.

The second line of string consists of a string representing t.

Output format :
The output displays the maximum length of subsequence found in t.



Refer to the sample output for formatting specifications.

Code constraints :
Strings s and t consist of alphabetical characters (a-z) with lengths ranging from 1 to 1000 characters.

Sample test cases :
Input 1 :
digger
biggerdiagram
Output 1 :
3
Input 2 :
iamneo
abcidfaiimon
Output 2 :
4

Q11:
Problem Statement



Have the function BracketCombinations(num) read num which will be an integer greater than or equal to zero, and return the number of valid combinations that can be formed with num pairs of parentheses.



For example, if the input is 3, then the possible combinations of 3 pairs of parenthesis, namely: ()()(), are ()()(), ()(()), (())(), ((())), and (()()). There are 5 total combinations when the input is 3, so your program should return 5.

Input format :
The input consists of a single integer n, representing the number of pairs of brackets.

Output format :
The output displays a single integer representing the number of possible combinations of well-formed bracket sequences.



Refer to the sample output for the formatting specifications.

Code constraints :
0 ≤ n ≤ 8

Sample test cases :
Input 1 :
3
Output 1 :
5
Input 2 :
2
Output 2 :
2
Input 3 :
0
Output 3 :
1

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