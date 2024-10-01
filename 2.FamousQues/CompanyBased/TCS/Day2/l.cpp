/*

Q10:
Problem Statement



You are given a list of item prices in your store and a customer's gift card balance. Your task is to find a pair of items the customer can purchase, ensuring the total price matches the gift card balance. If such a pair exists, print the prices of the two items. If multiple pairs are possible, print the price of the first occurred pair.



Write a function that takes item prices, the number of available items, and the gift card balance as input. The function should determine if there's a valid pair of items whose prices sum to the gift card balance and, if so, print the prices of the first occurred pair of items.



If no valid pair of items is found, print "No combination of items."

Input format :
The first line of input consists of an integer, representing the number of items in the store.

The second line of input consists of an array of integers separated by a space, representing the prices of the items.

The last line of input consists of an integer representing the customer's gift card balance.

Output format :
If there exists a combination of items whose prices sum up to the gift card balance, then print this combination.

If no such combination exists, print "No combination of items".



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

1 ≤ number of items ≤ 5

1 ≤ price ≤ 50

1 ≤ gift card balance ≤ 150

Sample test cases :
Input 1 :
3
10 20 30
50
Output 1 :
20 30
Input 2 :
4
10 15 20 30
58
Output 2 :
No combination of items
Input 3 :
4
3 5 7 5
10
Output 3 :
3 7

*/