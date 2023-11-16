// https://www.geeksforgeeks.org/problems/find-the-string/1



//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++

class Solution
{
private:
    // TC = O(K^N)
    // SC = O(N)
    void dfs (string& node, set<string>& visited, string& ans, int k) {
        visited.insert(node);
        
        for (int i = k - 1;  i >= 0; i--) {
            string child = node.substr(1) + to_string(i);
            
            if (!visited.count(child)) {
                ans += to_string(i);
                dfs(child, visited, ans, k);
            }
        }
    }
    
    string solve_approach_1(int n, int k) {
        string start = "";
        for (int i = 0; i < n; i++) {
            start += '0';
        }
        
        string ans = start;
        
        set<string> visited;
        
        dfs(start, visited, ans, k);
        
        return ans;
    }
public:
    string findString(int n, int k) {
        return solve_approach_1(n, k);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends