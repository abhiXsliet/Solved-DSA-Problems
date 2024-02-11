// https://www.geeksforgeeks.org/problems/recamans-sequence4856/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    // TC : O(N)
    // SC : O(N)
    vector<int> solve_approach_1(int n) {
        vector<int> result(n, 0);
        unordered_set<int> st;
        st.insert(0);
        for (int i = 1; i < n; i++) {
            int val = result[i - 1] - i;
            if ( (val < 0) || (st.find(val) != st.end()) ) {
                val = result[i - 1] + i;
                st.insert(val);
                result[i] = val;
            } else {
                st.insert(val);
                result[i] = val;
            }
        }
        return result;
    }
public:
    vector<int> recamanSequence(int n){
        return solve_approach_1(n);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends