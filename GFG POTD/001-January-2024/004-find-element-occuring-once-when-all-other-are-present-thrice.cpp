// https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

// Similar Question : https://leetcode.com/problems/single-number-ii/



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    // TC : O(N^2)
    // SC : O(1)
    int solve_brute_1(int nums[], int n) {
        for (int i = 0; i < n; i++) {
            bool isUnique = 1;
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] == nums[j]) {
                    isUnique = 0;
                    break;
                }
            }

            if(isUnique) {
                return nums[i];
            }
        }
        return 0;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int solve_brute_2(int arr[], int n) {
        sort(arr, arr + n);
        
        // Check first element
        if (arr[0] != arr[1]) 
            return arr[0]; 
        
        // Check last element
        if (arr[n-1] != arr[n-2]) 
            return arr[n-1]; 
        
        for (int i = 1; i < n-1; i++) {
            if (arr[i] != arr[i-1] && arr[i] != arr[i+1]) {
                return arr[i];
            }
        }
        
        return 0;
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_better(int arr[], int n) {
        unordered_map<int, int> mpp;
        
        for (int i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }
        
        for (auto& val : mpp) {
            if (val.second == 1) {
                return val.first;
            }
        }
        
        return 0;
    }
    
    // TC : O(32*N) ~= O(N)
    // SC : O(1)
    int solve_optimal_1(int nums[], int n) {
        int mask = 1, ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mask & nums[j]) 
                    cnt ++;
            }

            if (cnt % 3 != 0) 
                ans += mask;
                
            mask <<= 1;
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_optimal_2(int nums[], int n) {

        // Step-1 : Initialize variable ones and twos
        // ones stores if an element appears one time
        // twos stores if the element appears 2nd times
        // elements appeared 3rd times will neither stored in ones not in twos

                                    // 2  2  3  2
        int ele_appears_ones = 0;   // 2  0  1  3 --> 3 is the element which appeared only once
        int ele_appears_twos = 0;   // 0  2  0  0

        // Step-2: do calculations
        for (int i = 0; i < n; i++) {
            ele_appears_ones ^= nums[i];
            ele_appears_ones &= (~ele_appears_twos);

            ele_appears_twos ^= nums[i];
            ele_appears_twos &= (~ele_appears_ones);
        }
        return ele_appears_ones;
    }
    
    // TC : O(32 * N) ~= O(N)
    // SC : O(32)     ~= O(1)
    int solve_optimal_3(int arr[], int n) {
        int idx = 32;
        vector<int> storeBinary(idx, 0);
        
        for (int b = 0; b < 32; b++) {
            int cnt_ith_bit = 0;
            for (int i = 0; i < n; i++) {       
                int ith_bit = (arr[i] >> b) & 1;
                
                if (ith_bit == 1) {
                    cnt_ith_bit ++;
                }
            }
            
            if (cnt_ith_bit % 3 != 0) {
                storeBinary[idx - 1] = 1;
            }
            else storeBinary[idx - 1] = 0;
            idx --;
        }
        
        int decimal = 0;
        // Conver the 'storeBinary' bits into decimal 
        for (int i = 0; i < storeBinary.size(); i++) {
            decimal = decimal * 2 + storeBinary[i];
        }
        return decimal;
    }
    
    // TC : = O(N)
    // SC : = O(1)
    int solve_optimal_4(int arr[], int n) {
        // Initialize three_n to represent the 3n nature of numbers
        int three_n = -1;
        
        // Initialize three_n_plus_1 to represent the 3n+1 nature of numbers
        int three_n_plus_1 = 0;
        
        // Initialize three_n_plus_1 to represent the 3n+2 nature of numbers
        int three_n_plus_2 = 0;
        
        for (int i = 0; i < n; i++) {
            // Find the common bits with three_n, three_n_plus_1, and three_n_plus_2
            int common_with_three_n        = arr[i] & three_n;
            int common_with_three_n_plus_1 = arr[i] & three_n_plus_1;
            int common_with_three_n_plus_2 = arr[i] & three_n_plus_2;
            
            // Update three_n by removing the common bits
            three_n        = three_n        & (~common_with_three_n);
            // Add the common bits with three_n to three_n_plus_1
            three_n_plus_1 = three_n_plus_1 |   common_with_three_n;
            
            // Update three_n_plus_1 by removing the common bits
            three_n_plus_1 = three_n_plus_1 & (~common_with_three_n_plus_1);
            // Add the common bits with three_n_plus_1 to three_n_plus_2
            three_n_plus_2 = three_n_plus_2 |   common_with_three_n_plus_1;
            
            // Update three_n_plus_2 by removing the common bits
            three_n_plus_2 = three_n_plus_2 & (~common_with_three_n_plus_2);
            // Add the common bits with three_n_plus_2 to three_n
            three_n        = three_n        |   common_with_three_n_plus_2;
        }
        // Return the number that appears once in the array
        return three_n_plus_1;
    }
  public:
    int singleElement(int arr[] ,int N) {
        // return solve_brute_1(arr, N);
        
        // return solve_brute_2(arr, N);
        
        // return solve_better(arr, N);
        
        // return solve_optimal_1(arr, N);
        
        // return solve_optimal_2(arr, N);
        
        // return solve_optimal_3(arr, N);
        
        return solve_optimal_4(arr, N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends