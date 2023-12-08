// https://www.geeksforgeeks.org/problems/transform-to-prime4635/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// to store primes only
vector<int> primes;
bool computed = 0;

class Solution
{
    private:
    // TC = O(sqrt(sum))
    // SC = O(1)
    bool isPrime(int x) {
        if (x == 1) return 0;
        if (x == 2) return 1;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) return 0;
        }
        return 1;
    }
    
    void simpleSieve(int n) {
        vector<bool> prime(n, 1);
        prime[0] = prime[1] = 0;
    
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        
        for (int i = 0; i < prime.size(); i++) {
            if(prime[i]) {
                primes.push_back(i);
            }
        }
    }
    
    // TC = O(N * log(N) * log(N))
    // SC = O(N)
    int solve_approach_1(int arr[], int N) {
        // Pre-compute primes up to 1e6 + 10
        if (!computed) {
            simpleSieve(1e6 + 10);
            computed = 1;
        }
        
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        
        // binary search -> 
        // gives next greater prime element or if it is prime then return the same element
        auto p = lower_bound(primes.begin(), primes.end(), sum);
        return *p - sum;
    }
    
    // TC = O(N + sqrt(sum) * sum)
    // SC = O(1)
    int solve_approach_2(int arr[], int N) {
        int sum = 0;
        for (int i = 0; i < N; i++) 
            sum += arr[i];
        
        if (isPrime(sum)) return 0;
        for (int i = sum + 1; i <= 2 * sum; i++) {
            if (isPrime(i)) return i - sum;
        }
        return 0;
    }
    public:
    int minNumber(int arr[],int N)
    {
        // return solve_approach_1(arr, N);
        
        return solve_approach_2(arr, N);
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends