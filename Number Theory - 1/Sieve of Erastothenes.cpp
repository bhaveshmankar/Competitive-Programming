// Problem statement
// Given a number N, find number of primes in the range [1,N].

// Detailed explanation ( Input/output format, Notes, Images )
// Input Format:
// The only line of input consists of a number N
// Output Format:
// Print the number of primes in the range [1,N].
// Constraints:
// 1 ≤ N ≤ 10^6
// Sample Input :
// 3 
// Sample Output -
// 2

//   https://chatgpt.com/share/6db66a3f-99be-4923-b2ce-1e5ee1239ed2

#include<bits/stdc++.h>  // Includes all standard C++ libraries
using namespace std;

int makeSieve(int n) {
    // Create a boolean vector to track prime numbers up to n.
    // Initially, assume all numbers are prime.
    vector<bool> isPrime(n+1, true);

    // 0 and 1 are not prime numbers, so mark them as false.
    isPrime[0] = isPrime[1] = false;

    // Iterate from 2 up to the square root of n.
    // We only need to check up to sqrt(n) because if n = a * b, 
    // then one of the factors must be less than or equal to sqrt(n).
    for (int i = 2; i * i <= n; i++) {
        // If isPrime[i] is still true, then i is a prime number.
        if (isPrime[i]) {
            // Mark all multiples of i as non-prime.
            // Start marking from i*i because smaller multiples of i 
            // will have already been marked by smaller primes.
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count the number of primes found.
    int count = 0;
    for (int i = 0; i <= n; i++) {
        if (isPrime[i]) {
            count++;  // Increment count for each prime number.
        }
    }
    return count;  // Return the total number of prime numbers up to n.
}

int main() {
    int n;
    cin >> n;  // Read the input number n from the user.

    // Call the makeSieve function to count the number of primes up to n.
    int nPrimes = makeSieve(n);

    // Output the result, i.e., the number of prime numbers up to n.
    cout << nPrimes;

    return 0;  // Return 0 to indicate successful execution.
}
