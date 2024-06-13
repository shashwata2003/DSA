#include<iostream>
using namespace std;
/* 
-ve no. to binary 
 */
int main() {
    int n = -5;  // Example negative number
    int bits = sizeof(n) * 8;  // Number of bits in an integer

    cout << "Binary representation of " << n << ": ";

    for (int i = bits - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        cout << bit;
    }

    cout << endl;

    return 0;
}