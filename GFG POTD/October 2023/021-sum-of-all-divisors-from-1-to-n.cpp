// https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
private:
    // TC = O(N*N)
    long long solve_brute(int N) {
        long long sum1 = 0;
        long long sum2 = 0;
            
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i % j == 0) {
                    sum1 += j;
                }
            }
        }
        
        return sum1 + sum2;
    }
    
    // TC = O(N * sqrt(N))
    long long solve_better(int N) {
        long long sum = 0;
            
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j*j <= i; j++) {
                if (i % j == 0) {
                    // If divisors are same, add it only once
                    if (i / j == j) 
                        sum += j;
                    else // add both
                        sum += j + (i / j);
                }
            }
        }
        
        return sum;
    }
    
    // TC = O(N)
    long long solve_optimal(int N) {
        long long sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += (N/i) * i;
        }
        return sum;
    }
    
public:
    long long sumOfDivisors(int N)
    {
        // return solve_brute(N);
        
        // return solve_better(N);
        
        return solve_optimal(N);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends