// https://www.geeksforgeeks.org/problems/account-merge/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution{
  private:
    void makeSet(vector<int>& parent, vector<int>& rank, int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i]   = 0;
        }
    }
    
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;

        return parent[node] = findParent(parent, parent[node]);
    }
    
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        
        if (rank[u] < rank[v]) 
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u] ++;
        }
    }
  public:
    // TC : O(N*M*log(N))
    // SC : O(N*M)
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(parent, rank, n);
        
        unordered_map<string, int> mpp; // {mails, node as their row respective no.s as 0, 1, ...)
        
        // Step - 1 : connecting node and making disjoint sets & making the parent
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j < accounts[i].size(); j ++) {
                string mail = accounts[i][j];
                // if present then find their ultimate parent and make disjoint set
                if (mpp.find(mail) != mpp.end()) {
                    unionSet(i, mpp[mail], parent, rank);
                }
                else {  // absent
                    mpp[mail] = i;
                }
            }
        }
        
        // Step - 2 : merging mails a/c to disjoint set data structure
        vector<vector<string>> mergedMails(n);
        for (auto it : mpp) {
            string mail = it.first;
            int node    = findParent(parent, it.second);
            mergedMails[node].push_back(mail);
        }
        
        // Step - 3 : creating answer to return
        vector<vector<string>> result;
        for (int i = 0; i < n; i ++) {
            if (mergedMails[i].size() == 0) continue;
            
            sort(begin(mergedMails[i]), end(mergedMails[i]));
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            
            for (auto& mail : mergedMails[i]) {
                temp.push_back(mail);
            }
            
            result.push_back(temp);
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends