// Problem statement
// Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10^5
// 1 <= x, y <= 10^9
// Sample Input 1:
// 1
// 20 5
// Sample Output 1:
// 5
// Sample Input 2:
// 1
// 96 14
// Sample Output 2:
// 2


#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if (b == 0) {
    return a;
    }
    return gcd(b, a%b);
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
      cout<<gcd(a,b)<<endl;

    }
        return 0; 

}
