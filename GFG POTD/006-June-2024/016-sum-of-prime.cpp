// https://www.geeksforgeeks.org/problems/sum-of-prime4751/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  private:
    bool isPossible(vector<int>& searchSpace, int tar, int m) {
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = searchSpace[mid];
            if (val == tar) {
                return 1;
            } else if (val < tar) {
                low  = mid + 1;
            } else { 
                high = mid - 1;
            }
        }
        return 0;
    }
    
    // TC : O(N*log(log(N)) + M*log(M)) Where M = No. of Primes <= n/2
    // SC : O(N)        
    vector<int> approach_1(int n) {
        vector<int> primes(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i < n; i ++) {  // O(N*log(log(N)))
            for (int j = 2*i; j <= n; j = j + i) {
                primes[j] = 0;
            }
        }
        
        vector<int> possibleVal;
        for (int i = 0; i <= n; i++) {  // O(N)
            if (primes[i] == 1) {
                possibleVal.push_back(i);
            }
        }
        
        int m = possibleVal.size();
        for (int i = 0; i < m; i ++) {  // O(M*log(M))
            int tar = n - possibleVal[i];
            if (isPossible(possibleVal, tar, m)) {
                return {possibleVal[i], tar};
            }
        }
        return {-1, -1};
    }
    
    // TC : O(N*log(log(N)))
    // SC : O(N)
    vector<int> approach_2(int n) {
        vector<int> primes(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i < n; i ++) {  // O(log(log(N)))
            for (int j = 2*i; j <= n; j = j + i) {
                primes[j] = 0;
            }
        }
        
        vector<int> possibleVal;
        for (int i = 0; i <= n; i++) {  // O(N)
            if (primes[i] == 1) {
                int a = i;
                int b = n - i;
                if (primes[b] == 1) {
                    return {a, b};
                }
            }
        }
        
        return {-1, -1};
    }
  public:
    vector<int> getPrimes(int n) {
        // return approach_1(n);
        
        return approach_2(n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}
// } Driver Code Ends