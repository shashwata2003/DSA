#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given the house no. and the position of the houses return the house no. which is have the max difference and
consicutive in nature 
eg: 
3 7
1 9
2 0
5 15
4 30
ans: 4 5
 */

vector<int> findMaxDifferenceHouses(const vector<int>& houseNumbers, const vector<int>& positions) {
    int maxDifference = 0;
    vector<int> result;
    
    for (int i = 1; i < positions.size(); ++i) {
        int difference = abs(positions[i] - positions[i - 1]);
        if (difference > maxDifference) {
            maxDifference = difference;
            result.clear();
            result.push_back(houseNumbers[i]);
            result.push_back(houseNumbers[i - 1]);
        } else if (difference == maxDifference) {
            result.push_back(houseNumbers[i]);
            result.push_back(houseNumbers[i - 1]);
        }
    }
    
    return result;
}

int main() {
    vector<int> houseNumbers = {3, 1, 2, 5, 4};
    vector<int> positions = {7, 9, 0, 15, 30};
    
    vector<int> maxDiffHouses = findMaxDifferenceHouses(houseNumbers, positions);
    
    if (maxDiffHouses.size() > 0) {
        cout << "House numbers with max difference in consecutive positions: ";
        for (int i = 0; i < maxDiffHouses.size(); i += 2) {
            cout << maxDiffHouses[i] << " " << maxDiffHouses[i + 1] << " ";
        }
        cout << endl;
    } else {
        cout << "No consecutive houses found." << endl;
    }
    
    return 0;
}