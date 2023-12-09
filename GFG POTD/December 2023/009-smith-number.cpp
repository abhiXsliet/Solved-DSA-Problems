// https://www.geeksforgeeks.org/problems/smith-number4132/1



//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
    // TC = O(log(N))
    int sumDigit(int n) {
        int sum = 0;
        while(n) {
            sum += n % 10;
            n   /= 10;
        }
        return sum;
    }
    
    // TC = O(sqrt(N))
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    // TC = O(sqrt(N) * log(N))
    // SC = O(1)
    int getSum(int n) {
        int sum     = 0;
        int currNum = n; // to track the prime number
        
        // finding the prime factors -> eg., 985 = 5 * 197
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) { 
                sum += sumDigit(i);
                n   /= i;
            }
        }
        
        // eg = 197 
        if (n > 1) {
            sum += sumDigit(n);
        }
        
        // Incase of prime no.-> currNo. will be same as 'n'
        if (currNum == n) return -1;
        
        return sum;
    }
    
    // TC = O(N*log(N))
    // SC = O(1)
    int solve_approach_1(int n) {
        int sum = sumDigit(n);
        
        // since prime no. is not a composite number
        // A composite number which has more than two factors
        if (isPrime(n)) return 0;
        
        // variable to store the sum of digits of factors
        int sum2 = 0;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                int factorSum = sumDigit(i);
                while(n > 0 && n % i == 0) {
                    sum2 += factorSum;
                    n    /= i;
                }
            }
        }
        if (sum == sum2) return 1;
        return 0;
    }
    
    // TC = O(sqrt(N) * log(N))
    // SC = O(1)
    int solve_approach_2(int n) {
        int s1 = sumDigit(n);
        int s2 = getSum(n);
        
        // Incase of a prime no.
        if (s2 == -1) return 0;
        
        return s1 == s2 ? 1 : 0;
    }
    public:
    int smithNum(int n) {
        // return solve_approach_1(n);
        
        return solve_approach_2(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends