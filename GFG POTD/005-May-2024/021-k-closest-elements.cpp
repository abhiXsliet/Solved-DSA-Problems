// https://www.geeksforgeeks.org/problems/k-closest-elements3619/1



//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    static bool cmp(const pair<int, int>& a,const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first; 
        }
        
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<pair<int,int>>ans;
        
        for(int i=0;i<n;i++){
            ans.push_back({abs(arr[i]-x),arr[i]});
        }
       
        sort(ans.begin(),ans.end(),cmp);
        
        vector<int>res;
         
        for(int i=0;i<k;i++){
            if(ans[i].second==x)continue;
            res.push_back(ans[i].second);
        }
        
        if(res.size() < k)
            res.push_back(ans[k].second);
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends