// Problem statement
// In this problem you have to print all primes from given interval.

// Detailed explanation ( Input/output format, Notes, Images )
// Input Format:
// First line of input will contain T(number of test cases), each test case follows as.

// On each line are written two integers L and U separated by a blank. L - lower bound of 
// interval, U - upper bound of interval.
// Output Format:
// For each test case output must contain all primes from interval [L; U] in increasing order.
// Constraints:
// 1  <= T <= 100
// 1 <= L <= U <= 10^9
// 0 <= U - L <= 10^5
// Sample Input:
// 2
// 2 10
// 3 7
// Sample Output:
// 2 3 5 7
// 3 5 7 

// https://chatgpt.com/share/7e34571b-5a2e-4ae1-b0f6-f16dcaf31a56
// video from codebeyond's striver
#include <bits/stdc++.h>
using namespace std;

int N = 1000000; // Define a large number N for the sieve limit
vector<bool> sieve(N + 1); // Create a boolean vector 'sieve' to mark primes up to N

// Function to create the sieve of Eratosthenes up to N
void createSieve() {
    sieve[0] = sieve[1] = false; // 0 and 1 are not prime numbers
    for (int i = 2; i <= N; i++) {
        sieve[i] = true; // Initially, assume all numbers from 2 to N are prime
    }

    // Mark non-prime numbers in the sieve
    for (int i = 2; i * i <= N; i++) { // Only need to check up to the square root of N
        if (sieve[i] == true) { // If i is still marked as prime
            for (int j = i * i; j <= N; j += i) { // Mark all multiples of i as non-prime
                sieve[j] = false;
            }
        }
    }
}

// Function to generate all prime numbers up to N using the sieve
vector<int> generatePrimes(int N) {
    vector<int> ds;
    for (int i = 2; i <= N; i++) {
        if (sieve[i] == true) { // If i is prime
            ds.push_back(i); // Add i to the list of primes
        }
    }
    return ds;
}

int main() {
    createSieve(); // Generate the sieve of primes up to N

    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        int l, r;
        cin >> l >> r; // Read the range [l, r] for the current test case

        // Step 1: Generate all primes up to the square root of r
        vector<int> primes = generatePrimes(sqrt(r));

        // Step 2: Create a dummy array to mark primes in the range [l, r]
        int dummy[r - l + 1];
        for (int i = 0; i < r - l + 1; i++) {
            dummy[i] = 1; // Initially, assume all numbers in the range are prime
        }

        // Handle the special case where l == 1
        if (l == 1) {
            dummy[0] = 0; // 1 is not a prime number
        }

        // Step 3: Use the primes generated to mark non-prime numbers in the range [l, r]
        for (auto pr : primes) { // Iterate over each prime up to sqrt(r)
            int firstMultiple = (l / pr) * pr; // Calculate the first multiple of pr in the range

            if (firstMultiple < l) firstMultiple += pr; // Ensure the multiple is within the range
            if (firstMultiple == pr) firstMultiple += pr; // Avoid marking the prime number itself

            // Mark all multiples of pr as non-prime in the range [l, r]
            for (int j = max(firstMultiple, pr * pr); j <= r; j += pr) {
                dummy[j - l] = 0; // Mark as non-prime
            }
        }

        // Step 4: Output all prime numbers in the range [l, r]
        for (int i = l; i <= r; i++) {
            if (dummy[i - l] == 1) { // If the number is still marked as prime
                cout << i << " "; // Output the prime number
            }
        }
        cout << endl; // Move to the next line for the next test case
    }

    return 0;
}

     
