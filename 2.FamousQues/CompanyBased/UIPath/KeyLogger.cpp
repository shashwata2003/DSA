#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Problem statement-: Elliot made a KeyLogger for his friend Romero, so that he can see the passwords 
of his friend. Keylogger is a software that can tell you the buttons pressed in the keyboard without the 
consent of the user, and hence unethical. Elliot made it to hack Romero’s passwords. The one problem is, 
Romero writes the passwords in lowercase characters only, and the keylogger only takes the values of the keys. 
Like, for a it takes 1, for b 2, and for z 26. For a given number Elliot produces all combinations of 
passwords in a dictionary and starts a dictionary based password attack. For a given number, 
print all the possible passwords in a lexicographic order.

Input Format:

One line, denoting the value given by the keylogger
Output Format:

All possible combinations of keyloggers in new lines are lexicographically ordered.
Constraints:

2<=Number of digit in input<=1000
Sample Input:
1234

Sample Output:
abcd
awd
lcd

Explanation:
For 12, you can take 1,2 that is ab, or you can take l
 */

// Function to convert a number to its corresponding character
char to_char(const string& num_str) {
    return 'a' + stoi(num_str) - 1;
}

// Recursive function to generate combinations
void generate_combinations(const string& number, int index, string current_combination, vector<string>& combinations) {
    if (index == number.size()) {
        combinations.push_back(current_combination);
        return;
    }

    // Take one digit
    if (index < number.size()) {
        generate_combinations(number, index + 1, current_combination + to_char(string(1, number[index])), combinations);
    }

    // Take two digits
    if (index + 1 < number.size() && stoi(number.substr(index, 2)) >= 10 && stoi(number.substr(index, 2)) <= 26) {
        generate_combinations(number, index + 2, current_combination + to_char(number.substr(index, 2)), combinations);
    }
}

int main(){
    string number;
    cin >> number;

    vector<string> combinations;
    generate_combinations(number, 0, "", combinations);

    // Sort combinations lexicographically
    sort(combinations.begin(), combinations.end());

    // Print the combinations
    for (const string& combination : combinations) {
        cout << combination << endl;
    }

    return 0;
}