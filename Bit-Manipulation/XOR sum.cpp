/*
Problem statement
You are given two arrays, ‘arr1’ of size 'N' and ‘arr2’ of size 'M'. You need to create an array of bitwise AND of all the possible pairs between the elements of both arrays, and your task is to find the XOR sum of the array. The XOR sum of an array is equal to the XOR of all elements of the array.

Note:
The XOR sum of [A, B, C] is equal to A XOR B XOR C.
For example:
You are given an ‘arr1’ = [3, 2, 8] and ‘arr2’ = [1, 4, 3], therefore the AND of all possible pairs is [(3 & 1), (3 & 4), (3 & 3), (2 & 1), (2 & 4), (2 & 3), (8 & 1), (8 & 4), (8 & 3)]. So the resulting Array will be [1, 0, 3, 0, 0, 2, 0, 0, 0] therefore XOR sum of the result array is 0 . Hence the answer is 0.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains the single integer ‘T’ representing the number of test cases.

The first line of each test case contains two space-separated integers, ‘N’ and ‘M’, representing the size of ‘arr1’ and ‘arr2’, respectively.

The second line of  each test case contains ‘N’ space-separated integers representing the elements of the array ‘arr1’

The third line of each test case contains ‘M’ space-separated integers representing the elements of the array ‘arr2’.
Output Format:
For each test case, print the single integer representing the XOR sum of bitwise AND of all pairs of the arrays ‘arr1’ and ‘arr2’.

Print a separate line for each test case.
Constraints:
1 <= T <= 10
1 <= N, M <= 10^6
0 <= arr1[i], arr2[i] <= 10^9

Time Limit: 1 sec
Note:
You do not need to print anything. It has already been taken care of. Just implement the function.
Sample Input 1:
2
3 3
3 2 8
1 4 3
2 1
4 12
8
Sample Output 1:
0
8
Explanation :
For the first test case, ‘arr1’ = [3, 2, 8] and ‘arr2’ = [1, 4, 3], therefore the AND of all possible pairs is [(3 & 1), (3 & 4), (3 & 3), (2 & 1), (2 & 4), (2 & 3), (8 & 1), (8 & 4), (8 & 3)]. So the resulting array will be [1, 0, 3, 0, 0, 2, 0, 0, 0] therefore XOR sum of the result array is 0. Hence the answer is 0.

For the second test case ‘arr1’ = [4, 12] and ‘arr2’ = [8], therefore the AND of all possible pairs is [(4 & 8), (12 & 8)]. So the resulting array will be [0, 8] therefore XOR sum of the result array is 8. Hence the answer is 8.
Sample Input 2:
2
5 10
28 92 14 19 51
100 5 20 15 31 99 51 49 63 23
8 4
59 34 95 83 83 89 71 9
12 62 72 0
Sample Output 2:
44
80
*/

int xorSum(vector<int> &arr1, vector<int> &arr2)
{
    // Write your code here
    //intialise the xor sums
    int xorSum1=0;
    int xorSum2=0;

    //xor sum of first array
    for(int i=0; i<arr1.size(); i++){
        xorSum1 ^= arr1[i];
    }
    //xor sum of second array
    for(int i=0; i<arr2.size(); i++){
        xorSum2 ^= arr2[i];
    }
    //return AND of xorsums
    return xorSum1&xorSum2;
}
