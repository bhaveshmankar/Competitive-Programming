Problem statement
You are given an arbitrary array ‘arr’ consisting of N non-negative integers, where every element appears thrice except one. You need to find the element that appears only once.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
4 <= N <= 10^4
0 <= arr[i] < 10^9
Time Limit: 1sec
Sample Input 1:
1
4
1 2 1 1
Sample Output 1:
2
Explanation For Sample Input 1:
Clearly, the 2 appears once while 1 appears thrice. Hence, 2 is the output.
Sample Input 2:
1
7 
1 3 3 3 1 1 4
Sample Output 2:
4
        

// Code 

//https://chatgpt.com/share/13c7b6e0-4c51-435d-9ae2-398865192cc9

int elementThatAppearsOnce(vector<int> arr) {
	// Write your code here.
	    // Initialize a vector to store the count of bits
    std::vector<int> bit_count(32, 0);

    // Count bits for each number
    for (int num : arr) {
        for (int i = 0; i < 32; ++i) {
            if (num & (1 << i)) {
                bit_count[i] += 1;
            }
        }
    }

    // Reconstruct the unique number from the bit counts
    int unique_number = 0;
    for (int i = 0; i < 32; ++i) {
        if (bit_count[i] % 3 != 0) {
            unique_number |= (1 << i);
        }
    }

    return unique_number;
}
