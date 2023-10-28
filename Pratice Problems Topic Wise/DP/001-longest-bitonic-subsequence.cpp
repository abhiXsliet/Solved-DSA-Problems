// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int solve(vector<int>nums, int idx) {
        int n = nums.size();
        
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }
        
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (maxi < lis[i] + lds[i] - 1)
                maxi = lis[i] + lds[i] - 1;
        }
        
        return maxi;
    }
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    return solve(nums, 0);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends