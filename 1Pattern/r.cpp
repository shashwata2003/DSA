#include<iostream>
using namespace std;
/* 
xxxx
 xxx
  xx
   x
*/
int main() {
    int n = 4, i = 0;
    while (i < n) {
        int spaces = n - i - 1;  // Calculate spaces correctly
        int j = n - spaces;      // Adjust stars accordingly

        // Print spaces
        while (spaces) {
            cout << " ";
            spaces--;  // Decrement spaces
        }

        // Print stars
        while (j) {
            cout << "X";
            j--;
        }

        cout << endl;
        i++;
    }

    return 0;
}