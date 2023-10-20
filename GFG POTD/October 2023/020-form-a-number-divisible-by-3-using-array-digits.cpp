// https://practice.geeksforgeeks.org/problems/form-a-number-divisible-by-3-using-array-digits0717/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    // TC = O(N)
    // SC = O(N)
    int solve_brute(int n, int arr[]) {
        string str = "";
        for (int i = 0; i < n; i++) {
            string s = to_string(arr[i]);
            str += s;
        }
        
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            // Convert the character to a string
            // string charStr(1, str[i]);
            // sum += stoi(charStr);
            
            char ch = str[i];
            sum += ch - '0';
        }
        
        if (sum % 3 == 0) return 1;
        else return 0;
    }
    
    // TC = O(N)
    // SC = O(1)
    int solve_optimal(int n, int arr[]) {
        int sum = 0;
        int num = 0;
        
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }
        }
        
        return sum % 3 == 0 ? 1 : 0;
    }
  public:
    int isPossible(int N, int arr[]) {
        // return solve_brute(N, arr);
        
        return solve_optimal(N, arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends