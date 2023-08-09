// https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1



//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        long long int ans = 1;
        for(long long int i  = 2; i*i <= N; i++) {
            while(N % i == 0) {
                ans = max(ans, i);
                N /= i;
            }
        }
        if(N > 1) return N; 
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends