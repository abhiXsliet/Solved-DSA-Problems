// https://www.geeksforgeeks.org/problems/water-the-plants--170646/1



//{ Driver Code Starts
// driver code
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    // TC : O(N*log(N))
    // SC : O(N)
    int solve_appraoch_1(int gallery[], int n) {
        vector<pair<int, int>> ranges;
        
        for (int i = 0; i < n; i++) {
            if (gallery[i] != -1) {
                int leftRange  = max(0, i - gallery[i]);
                int rightRange = min(n - 1, i + gallery[i]);
                
                ranges.push_back({leftRange, rightRange});
            }
        }

        sort(begin(ranges), end(ranges));
        
        int idx    = 0;
        int tapCnt = 0;
        int target = 0;
        
        while (target < n) {
            int maxRange = -1;
            
            while (idx < ranges.size()) {
                if (ranges[idx].first <= target) {
                    maxRange = max(maxRange, ranges[idx].second);
                    idx ++;
                }
                else break;
            }
            
            if (maxRange < target) {
                return -1;
            }
            
            tapCnt += 1;
            target = maxRange + 1;
        }
        
        return tapCnt;
    }
    
    public:
    int min_sprinklers(int gallery[], int n)
    {
        return solve_appraoch_1(gallery, n);
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
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends