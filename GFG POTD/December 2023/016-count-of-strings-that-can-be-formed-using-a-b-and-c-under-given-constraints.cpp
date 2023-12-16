// https://www.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints1135/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends

long long getNCR(int a, int b) {
    long ans = 1;
    for (long i = 0; i < b; i++) {
        ans *= (a - i);
        ans /= (i + 1);
    }
    return ans;
}

// TC : O(1)
// SC : O(1)
long long solve_brute(long long int n) {
    long res = 0;
    for (int b = 0; b <= 1; b++) { // b could be either 0 or 1-times
        for (int c = 0; c <= 2; c++) {  // c could be either 0, 1 or 2-times
            long val = 0;
            if (b == 0 && c == 0) res += 1;
            if (b == 0 && c != 0) {
                res += getNCR(n, c);
            }
            if (b != 0 && c == 0) {
                res += getNCR(n, b);
            }
            if (b != 0 && c != 0) {
                val = 1;
                bool flag = 1;
                for (int i = 0; i < 2; i++) {
                    if (flag) {
                        val *= getNCR(n-i, min(b, c));
                        flag = 0;
                    }
                    else val *= getNCR(n-i, max(b, c));
                }
                res += val;
            }
        }
    }
    return res;
}

// TC : O(1)
// SC : O(1)
long long solve_optimal(long long n) {
    // Case 1 : only 'a' at all places                      = 1-way
    // Case 2 : 'b' could be at any of the n-places         = n-ways 
    // Case 3 : 'c' could be at any of the n-places         = n-ways
    // Case 4 : 1-'b' & 1-'c' & at remaining places put 'a' = n * (n - 1)
    // Case 5 : 2-'c' & put 'a' at remaining places         = n * (n - 1) / 2
    // Case 6 : 2-'c' & 1-'b' & at remaining places put 'a' = n * (n - 1)* (n - 2) / 2
    return 1 + n + n + n*(n - 1) + n*(n - 1)/2 + n*(n - 1)*(n - 2)/2;
}

long long int countStr(long long int n){
    // return solve_brute(n);
    
    return solve_optimal(n);
}