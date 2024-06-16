// https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-given-n-ranges/1




//{ Driver Code Starts
/* Driver program to test above function */
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//User function Template for C++

class Solution{
    private:
    // TC : O(N*log(N))
    // SC : O(1) -> Auxiliary Space
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals, int n) {
        sort(begin(intervals), end(intervals));

        vector<vector<int>> result;
        for (auto& interval : intervals) {
            
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            }
            else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
    public:
    // TC : O(n*log(n) + q*n)
    // SC : O(1)
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        vector<vector<int>> mergedIntervals = mergeIntervals(range, n);
        
        vector<int> result;
        for (int& query : queries) {
            bool found = 0;
            for (auto& interval : mergedIntervals) {
                int range = interval[1] - interval[0] + 1;
                if (query <= range) {
                    result.push_back(interval[0] + query - 1);
                    found = 1;
                    break;
                } else {
                    query -= interval[1];
                }
            }
            if (found == 0) {
                result.push_back(-1);
            }
        }
        return result;
    } 
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends