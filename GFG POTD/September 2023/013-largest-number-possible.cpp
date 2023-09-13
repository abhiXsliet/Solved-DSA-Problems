// https://practice.geeksforgeeks.org/problems/largest-number-possible5028/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    // TC = O(N), SC = O(1)
    string solve_brute(int N, int S) {
        
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += 9;
        }
        
        long long diff = sum - S;
        
        if (diff < 0 || (S == 0 && N > 1)) return "-1";
        else {
            string str = "";
            for(int i = 0; i < N; i++) {
                str.push_back('9');
            }

            for (int i = N-1; i >= 0 && diff > 0; i--) {
                if(str[i] != '0') {
                    int toSub = min(diff, (long long)str[i]-'0');
                    str[i] -= toSub;
                    diff -= toSub;
                } 
            }
            return str;
        }
    }
    
    // TC = O(N), SC = O(1)
    string solve_optimal(int N, int S) {
        string ans = "";
        if (S == 0 && N > 1) return "-1";
        
        for (int i = 0; i < N; i++) {
            if (S > 9) {
                ans += '9';
                S -= 9;
            } 
            else {
                ans += to_string(S);
                S -= S;
            }
        }
        
        if (S != 0) return "-1";
        
        return ans;
    }
public:
    string findLargest(int N, int S){
        
        // return solve_brute(N, S);
        
        return solve_optimal(N, S);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends