// Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm

// int gcd(int a, int b)
// {

//     if (b==0)
//     return a;
//     else
//     return gcd(b,a%b);
// }
// and challenges to Varun to calculate gcd of two integers, one is a little integer and another integer can have 10^4 digits.

// Your task is to help Varun an efficient code for the challenge of Sanchit.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 100
// 1 <= A <= 4*10^5
// 1 <= |B| <= 10^4
// where |B| is the length of the integer B 
// Sample Input:
// 2
// 2 6
// 10 11
// Sample Output:
// 2
// 1
   
// https://chatgpt.com/share/995c2526-7a94-472f-ab20-257b83994a30

#include<bits/stdc++.h>
using namespace std;

// Function to convert a large number represented as a string to an integer modulo 'a'.
int convertInt(string &s, int a) {
    int number = 0;
    
    // Loop through each digit of the string 's'.
    for (int i = 0; i < s.size(); i++) {
        // Update the number by shifting the current value by one decimal place and adding the new digit.
        // The subtraction of '0' from 's[i]' converts the character to its integer value.
        // The result is taken modulo 'a' to prevent overflow and to keep the number within manageable limits.
        number = (number * 10 + s[i] - '0') % a;
    }
    
    // Return the reduced number modulo 'a'.
    return number;
}

// Function to calculate the Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm.
int gcd(int a, int b) {
    if (b == 0) {
        // Base case: if 'b' is 0, the GCD is 'a'.
        return a;
    }
    // Recursive call: GCD of 'b' and the remainder of 'a' divided by 'b'.
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t; // Read the number of test cases.
    
    while (t--) {
        int a;
        string s;
        cin >> a; // Read the integer 'a'.
        cin >> s; // Read the large number as a string 's'.
        
        // Convert the large string number 's' to an integer modulo 'a'.
        int b = convertInt(s, a);
        
        // Calculate and output the GCD of 'a' and the reduced number 'b'.
        cout << gcd(a, b) << endl;
    }
    
    return 0;
}

