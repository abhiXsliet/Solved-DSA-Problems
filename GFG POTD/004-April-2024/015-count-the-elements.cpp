// https://www.geeksforgeeks.org/problems/count-the-elements1529/1 



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(q * M) where M = No. of map size
    // SC : O(M)
    vector<int> solve_brute(vector<int>& a, vector<int>& b, int n, vector<int>& query, int q) {
        unordered_map<int, int> mpp;
        for (int& num : b) {
            mpp[num] ++;
        }
        
        vector<int> result;
        for (int& q : query) {
            int a_ele = a[q];
            int cntEle = 0;
            for (auto& it : mpp) {
                if (it.first <= a_ele) {
                    cntEle += it.second;
                }
            }
            result.push_back(cntEle);
        }
        return result;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    vector<int> solve_better(vector<int>& a, vector<int>& b, int n, vector<int>& query, int q) {
        vector<int> ans;
        sort(b.begin(), b.end());
        
        for(int i=0 ;i<query.size() ;i++){
            
            int index = query[i];
            int val = a[index];
            int cnt = upper_bound(b.begin(), b.end(), val) - b.begin();
            
            ans.push_back(cnt);
        }
        
        return ans;
    }

    // TC : O(n+q+maximum of a and b) 
    // SC : O(maximum of a and b)
    vector<int> solve_optimal(vector<int>& a, vector<int>& b, int n, vector<int>& query, int q) {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, max(a[i], b[i]));
        }
        
        vector<int> freq(maxi + 1, 0);
        for (int& num : b) {
            freq[num] ++;
        }
        
        // calculate the prefix of freq
        for (int i = 1; i <= maxi; i++) {
            freq[i] += freq[i - 1];
        }
        
        vector<int> result;
        for (int& q : query) {
            result.push_back(freq[a[q]]);
        }
        return result;
    }
  public:
    vector<int> countElements(vector<int>& a, vector<int>& b, int n, vector<int>& query, int q) {
        // return solve_brute(a, b, query, q);
        
        // return solve_better(a, b, n, query, q);
        
        return solve_optimal(a, b, n, query, q);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends