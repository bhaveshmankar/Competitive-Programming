/* 
C. Bits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's denote as  the number of bits set ('1' bits) in the binary representation of the non-negative integer x.

You are given multiple queries consisting of pairs of integers l and r. For each query, find the x, such that l ≤ x ≤ r, and  is maximum possible. If there are multiple such numbers find the smallest of them.

Input
The first line contains integer n — the number of queries (1 ≤ n ≤ 10000).

Each of the following n lines contain two integers li, ri — the arguments for the corresponding query (0 ≤ li ≤ ri ≤ 1018).

Output
For each query print the answer in a separate line.

Examples
inputCopy
3
1 2
2 4
1 10
outputCopy
1
3
7
Note
The binary representations of numbers from 1 to 10 are listed below:

110 = 12

210 = 102

310 = 112

410 = 1002

510 = 1012

610 = 1102

710 = 1112

810 = 10002

910 = 10012

1010 = 10102

*/

// Final Solution
//https://chatgpt.com/share/0513269c-1a70-4a55-a740-4b1587f157d0

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; // Number of queries
    long long L, R; // Range [L, R]
    long long res; // Resultant number with maximum set bits

    cin >> t; // Reading the number of queries

    while(t--) {
        cin >> L >> R; // Reading each query range [L, R]

        res = L; // Initialize result with L

        // Attempt to set each bit from the least significant to the most significant
        for(int i = 0; i < 64; i++) {
            if((res & (1LL << i)) == 0) { // Check if the i-th bit is not set
                long long temp = res + (1LL << i); // Set the i-th bit

                if(temp > R) break; // If it exceeds R, break out of the loop
                else res = temp; // Otherwise, update result
            }
        }

        cout << res << endl; // Output the result for the current query
    }

    return 0;
}
