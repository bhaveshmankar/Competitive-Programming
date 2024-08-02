/*
  Problem statement
You are given an integer N. You need to return an integer M, in which only one bit is set which at the position of a lowest set bit of N (from right to left).

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input will contain T(number of the test case), each test case follows as.
The only line of each test case contains an integer N.
Output Format:
Integer M for each test case in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
Sample Input 1 :
1
7
Sample Output 1 :
1
Sample Input 2 :
1
12
Sample Output 2 :
4
  */

//https://chatgpt.com/share/2244fc9b-43d3-4659-b8d2-42c86bac6790
#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    return (n & -n);
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        cout<<solve(N)<<endl;
    }
    return 0;
}
