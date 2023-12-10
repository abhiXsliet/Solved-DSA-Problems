// https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1



//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    private:
    // TC = O(N*N*N)
    // SC = O(1) 
    bool solve_brute(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                
                if (sum == 0) return true;
            }
        }
        return false;
    }

    // TC = O(N*N)
    // SC = O(1)  
    bool solve_better(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                
                if (sum == 0) return true;
            }
        }
        return false;
    }
    
    // TC = O(N)
    // SC = O(N)   
    bool solve_optimal(int arr[], int n) {
        unordered_map<int, int> mpp;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (sum == 0) {
                return true;
            }
            else {
                if (mpp[sum]) {
                    return true;
                }
                else mpp[sum] = 1;
            }
        }
        return false;
    }
    
    // TC = O(N)
    // SC = O(N)
    bool solve_optimal_2(int arr[], int n) {
        unordered_set<int> st;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (st.find(sum) != st.end()) 
                return true;
                
            st.insert(sum);
            sum += arr[i];
        }
        return false;
    }
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        // return solve_brute(arr, n);
        
        // return solve_better(arr, n);
        
        // return solve_optimal_1(arr, n);
        
        return solve_optimal_2(arr, n);
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
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
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends