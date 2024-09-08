#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>  // For transform
using namespace std;

// Function to convert a single octet (in decimal) to a hexadecimal string in uppercase
string toHex(int num) {
    stringstream ss;
    ss << hex << setw(2) << setfill('0') << num;
    string hexStr = ss.str();

    // Convert to uppercase
    transform(hexStr.begin(), hexStr.end(), hexStr.begin(), ::toupper);

    return hexStr;
}

string solve(string s) {
    vector<int> octets;
    string temp = "";

    // Parse the input string to extract the octets
    for (char i : s) {
        if (i != '.') {
            temp += i;  // Accumulate characters for the current octet
        } else {
            // Convert the accumulated string to an integer and store it in the octets vector
            octets.push_back(stoi(temp));
            temp = "";  // Reset temp for the next octet
        }
    }

    // Add the last octet to the vector
    if (!temp.empty()) {
        octets.push_back(stoi(temp));
    }

    // Validate that there are exactly 4 octets
    if (octets.size() != 4) {
        return "Invalid input";
    }

    // Convert the first two octets to hexadecimal and concatenate them
    string ans = toHex(octets[0]) + toHex(octets[1]);

    // Add the separator "::"
    ans += "::";

    // Convert the last two octets to hexadecimal and concatenate them
    ans += toHex(octets[2]) + toHex(octets[3]);

    // Prepend "::FFFF:" for the final output
    ans = "::FFFF:" + ans;

    return ans;
}

int main() {
    string s = "10.11.12.13.14";  // Change this input for testing
    cout << solve(s) << endl;
    return 0;
}
