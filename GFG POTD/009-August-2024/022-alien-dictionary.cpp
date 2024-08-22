// https://www.geeksforgeeks.org/problems/alien-dictionary/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution{
    private:
    // TC : O(K)
    // SC : O(K) -> Recusive Depth
    void dfs(int src, unordered_map<int, vector<int>>& adj, vector<bool>& vis, stack<int>& stk) {
        vis[src] = 1;
        for (auto& nbr : adj[src]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, stk);
            }
        }
        stk.push(src);
    }
    
    // TC : O(K)
    // SC : O(K)
    vector<int> DFS(unordered_map<int, vector<int>>& adj, int K) {
        vector<bool> visited(K, 0);
        stack<int> stk;
        for (int i = 0; i < K; i ++) {
            if (!visited[i]) {
                dfs(i, adj, visited, stk);
            }
        }
        
        vector<int> result;
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
    
    // TC : O(K)
    // SC : O(K)
    vector<int> BFS(unordered_map<int, vector<int>>& adj, vector<int>& inDegree) {
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i ++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> result;
        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            
            result.push_back(fNode);
            
            for (int& v : adj[fNode]) {
                inDegree[v] --;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return result;
    }
    
    // TC : O(N)
    void prepareAdj(string dict[], unordered_map<int, vector<int>>& adj, int N) {
        for (int i = 0; i < N - 1; i ++) {
            string w1 = dict[i];
            string w2 = dict[i + 1];
            
            int j    = 0;
            int wLen = min(w1.length(), w2.length());
            while (j < wLen) {
                if (w1[j] == w2[j]) j ++;
                else break;
            }
            
            if (j >= wLen) continue;
            
            int u = w1[j] - 'a';
            int v = w2[j] - 'a';
            adj[u].push_back(v);
        }
    }

    // TC : O(N + K)
    // SC : O(K)
    string approach_1(string dict[], int N, int K) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(K, 0);
        
        prepareAdj(dict, adj, N);

        for (auto& it : adj) {
            for (int& v : it.second) {
                inDegree[v] ++;
            }
        }
        
        vector<int> topoSort = BFS(adj, inDegree);  

        string result;
        for (int& t : topoSort) {
            result += t + 'a';
        }
        return result;
    }
    
    // TC : O(N + K)
    // SC : O(K)
    string approach_2(string dict[], int N, int K) {
        unordered_map<int, vector<int>> adj;
        prepareAdj(dict, adj, N);
        
        vector<int> topoSort = DFS(adj, K); 

        string result;
        for (int& t : topoSort) {
            result += t + 'a';
        }
        return result;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        return approach_1(dict, N, K);  // Using BFS (Kahn's Algo)
        
        return approach_2(dict, N, K);  // Using DFS
    }
};


//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends