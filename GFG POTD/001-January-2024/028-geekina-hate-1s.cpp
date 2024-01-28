// https://www.geeksforgeeks.org/problems/geekina-hate-1s/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // dpTable stores the results of subproblems
    vector<vector<vector<long long>>> dpTable;

    // findNthNumber is the main function that finds the nth number with at most k set bits
    long long findNthNumber(int n, int k) {
        // Initialize the binary search range
        long long low = 0, high = 1e18;

        // Initialize the dpTable
        dpTable = vector<vector<vector<long long>>>(2, vector<vector<long long>>(65, vector<long long>(65, -1)));

        // Binary search
        while (low < high) {
            long long mid = low + (high - low) / 2;
            // If there are at least n numbers with at most k set bits and value <= mid
            if (countNumbers(mid, k) >= n) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // Return the nth number
        return low;
    }

private:
    // countNumbers returns the count of numbers <= x with at most k set bits
    long long countNumbers(long long x, int k) {
        string binary = bitset<64>(x).to_string();
        resetDPTable();
        return countUsingDP(binary, binary.length(), 1, k);
    }

    // countUsingDP uses dynamic programming to count the numbers
    long long countUsingDP(string &binary, int n, int tight, int k){
        if(k < 0)
            return 0;
        if(n == 0){
            return 1;
        }
        if(dpTable[tight][k][n] != -1)
            return dpTable[tight][k][n];

        // Calculate the upper bound for the current digit
        int upperBound = (tight == 1 ? (int)(binary[binary.length() - n] - '0') : 1);

        long long count = 0;
        for(int digit = 0; digit <= upperBound; digit++){
            if(digit == upperBound)
                count += countUsingDP(binary, n - 1, tight, k - digit);
            else
                count += countUsingDP(binary, n - 1, 0, k - digit);
        }

        return dpTable[tight][k][n] = count;
    }

    // resetDPTable resets the dpTable for a new binary search iteration
    void resetDPTable(){
        for(int i = 0; i < 65; i++){
            for(int j = 0; j < 65; j++){
                dpTable[0][i][j] = dpTable[1][i][j] = -1;
            }
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        long long res = obj.findNthNumber(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends