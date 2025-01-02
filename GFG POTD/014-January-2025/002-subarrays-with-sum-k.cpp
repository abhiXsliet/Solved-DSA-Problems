// https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//User function Template for C++
class Solution{
    private:
    // TC = O(N * N * N) -> TLE
    // SC = O(1)
    int solve_brute(vector<int>& arr, int n, int k) {
        int no_of_subarrays = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                if (sum == k) 
                    no_of_subarrays++;
            }
        }
        return no_of_subarrays;
    }
    
    // TC = O(N * N) -> TLE
    // SC = O(1)
    int solve_better(vector<int>& arr, int n, int k) {
        int no_of_subarrays = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) 
                    no_of_subarrays++;
            }
        }
        return no_of_subarrays;
    }
    
    // TC => O(N)
    // SC => O(N)
    // Optimal code if the array has both +ve and -ve elements
    int solve_optimal(vector<int>& arr, int n, int k){
        int no_of_subarrays = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            no_of_subarrays += mpp[sum - k];
            mpp[sum]++;
        }
        return no_of_subarrays;
    }
    public:
    int countSubarrays(vector<int>& arr, int k) {
        int N = arr.size();
        // return solve_brute(arr, N, k);
        // return solve_better(arr, N, k);
        return solve_optimal(arr, N, k);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends