// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-113/problems


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	int TotalPairs(vector<int>&nums, int x, int y){
	    int n = nums.size();
	    int ans = 0;
	    sort(nums.begin(), nums.end());
	    
	    for(int i = 0; i < n; i++) {
	        // first occurance
	        int l = lower_bound( nums.begin()+i+1, nums.end(), 
	                ( (x + (nums[i] - 1))/nums[i] ) ) - nums.begin(); // (ceil)(x) = (x+(nums[i]-1))
	                
	        // last occurance
	        int r = upper_bound( nums.begin()+i+1, nums.end(), 
	                ( (y)/nums[i]) ) - nums.begin() - 1;
	        
	        if(l <= r) {
	            ans += ( r - l ) + 1;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, x, y;
		cin >> n >> x >> y;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.TotalPairs(nums, x, y);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends