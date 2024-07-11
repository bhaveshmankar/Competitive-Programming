/*
  Problem statement
You are given an array 'nums' consisting of first N positive integers. But from the N integers, one of the integers occurs twice in the array, and one of the integers is missing. You need to determine the repeating and the missing integer.

Example:
Let the array be [1, 2, 3, 4, 4, 5]. In the given array ‘4’ occurs twice and the number ‘6’ is missing.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100 
2 <= N <= 10^4
1 <= nums[i] <= N

Time Limit: 1 sec
Sample Input 1:
2
5
1 4 2 5 2
2
2 2    
Sample Output 1:
2 3
2 1
Explanation For Sample Input 1:
For the first test case we have, array: [1, 4, 2, 5, 2] and N = 5.

In the given array ‘2’ occurs twice and the number ‘3’ is missing. Hence, we output 2 and 3 for the repeating and the missing number, respectively.

For the second test case we have, array: [2, 2] and N = 2.

In the given array ‘2’ occurs twice and the number ‘1’ is missing. Hence, we output 2 and 1 for the repeating and the missing number, respectively.
Sample Input 2:
3
4
1 2 2 3
10
1 3 4 5 5 6 7 8 9 10
3
1 2 2
Sample Output 2:
2 4 
2 5 
2 3
  */

// final solution
//https://chatgpt.com/share/4a541c2a-72c1-4fdf-803b-c81330fff3d5
vector<int> findRepeatingAndMissingNumbers(vector<int> nums) {
    int n = nums.size();
    int xor1 = 0, xor2 = 0;

    // XOR all the elements in the array
    for (int i = 0; i < n; i++) {
        xor1 ^= nums[i];
    }

    // XOR all the numbers from 1 to N
    for (int i = 1; i <= n; i++) {
        xor2 ^= i;
    }

    // XOR both results to get the XOR of the missing and repeating numbers
    int xor_result = xor1 ^ xor2;

    // Find a set bit (rightmost set bit)
    int set_bit_no = xor_result & ~(xor_result - 1);

    // Initialize missing and repeating to 0
    int missing = 0, repeating = 0;

    // Separate elements into two groups based on the set bit
    for (int i = 0; i < n; i++) {
        if (nums[i] & set_bit_no)
            repeating ^= nums[i];
        else
            missing ^= nums[i];
    }

    // Separate numbers from 1 to N into two groups based on the set bit
    for (int i = 1; i <= n; i++) {
        if (i & set_bit_no)
            repeating ^= i;
        else
            missing ^= i;
    }

    // Determine which is missing and which is repeating
    for (int i = 0; i < n; i++) {
        if (nums[i] == repeating) {
            return {repeating, missing};
        }
    }

    return {missing, repeating};
}
