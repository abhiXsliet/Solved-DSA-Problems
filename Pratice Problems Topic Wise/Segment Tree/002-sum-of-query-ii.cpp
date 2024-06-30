// https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void buildTree(int i, int l, int r, int arr[], vector<int>& segTree) {
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }
        
        int mid = (l + r) >> 1;
        buildTree(2*i + 1, l, mid, arr, segTree);
        buildTree(2*i + 2, mid + 1, r, arr, segTree);
        
        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }
    
    int Query(int i, int l, int r, int start, int end, vector<int>& segTree) {
        if (l > end || r < start) { // out of bound
            return 0;
        } 
        if (l >= start && r <= end) { // completely overlap
            return segTree[i];
        }   
        // partially overlap
        int mid = (l + r) >> 1;
        return (Query(2*i + 1, l, mid, start, end, segTree) + 
                Query(2*i + 2, mid + 1, r, start, end, segTree));
        
    }
public:
    // TC : O(N) + O(Q*log(N)) Where Q = No. of queries & N = Size of Array
    // SC : O(N)
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> segTree(4*n);
        
        buildTree(0, 0, n - 1, arr, segTree);
        
        vector<int> result;
        for (int i = 0; i < 2*q; i += 2) {
            int start = queries[i] - 1;
            int end   = queries[i + 1] - 1;
            
            result.push_back(Query(0, 0, n - 1, start, end, segTree));
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends