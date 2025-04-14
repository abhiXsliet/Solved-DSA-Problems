// https://www.geeksforgeeks.org/problems/alien-dictionary/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    bool dfs(int src, unordered_map<int, vector<int>> &adj, vector<int> &states, stack<int> &stk) {
        states[src] = 1;    // visiting curr node
        for (int &nbr : adj[src]) {
            if (states[nbr] == 1) // found a cycle : already visited in current dfs
                return false;
            if (states[nbr] == 0) { // not visited then do dfs
                if (!dfs(nbr, adj, states, stk)) {
                    return false;
                }   
            }
        }
        states[src] = 2;   // visit done 
        stk.push(src);
        return true;
    }
    
    vector<int> topoSortUsingDfs(unordered_map<int, vector<int>> &adj, vector<int> &indegree) {
        vector<int> topoOrder;
        stack<int> stk;
        vector<int> states(26, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        for (int i = 0; i < 26; i ++) {
            if (!states[i] && indegree[i] != -1) {
                if (!dfs(i, adj, states, stk))
                    return {};
            }
        }
        while (!stk.empty()) {
            topoOrder.push_back(stk.top());
            stk.pop();
        }
        return topoOrder;
    }
    
    vector<int> topoSortUsingBfs(unordered_map<int, vector<int>> &adj, vector<int> &indegree) {
        queue<int> q;
        for (int i = 0; i < indegree.size(); i ++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        vector<int> topoOrder;
        while (!q.empty()) {
            int fNode = q.front();
            q.pop();
            
            topoOrder.push_back(fNode);
            for (int &nbr : adj[fNode]) {
                indegree[nbr] --;
                if (!indegree[nbr]) {
                    q.push(nbr);
                }
            }
        }
        return topoOrder;
    }
  public:
    // TC : O(N * M)
    // SC : O(N * M)
    string findOrder(vector<string> &words) {
        int n = words.size();

        unordered_map<int, vector<int>> adj;
        
        vector<int> indegree(26, -1);
        int totalChars = 0;
        for (const string &word : words) {
            for (const char &ch : word) {
                if (indegree[ch - 'a'] == -1) {
                    indegree[ch - 'a'] = 0;
                    totalChars += 1;
                }
            }
        }

        for (int i = 0; i < n - 1; i ++) {
            string first  = words[i];
            string second = words[i + 1];
            
            int minL = min(first.length(), second.length());
            bool found = false;
            
            for (int j = 0; j < minL; j ++) {
                if (first[j] != second[j]) {
                    int u = first[j] - 'a';
                    int v = second[j] - 'a';
                    adj[u].push_back(v);
                    indegree[v] ++;
                    found = true;
                    break;
                }
            }
            
            // invalid case : ["abc", "ab"]
            if (!found && (first.length() > second.length()))
                return "";
        }
        
        // vector<int> topoSort = topoSortUsingBfs(adj, indegree);  // Khan's Algo
        vector<int> topoSort = topoSortUsingDfs(adj, indegree);
        
        string result;
        for (int &i : topoSort) {
            result += (i + 'a');
        }
        
        // Incomplete ordering if totalChars != obtained result size 
        return result.size() != totalChars ? "" : result;
    }
};

//{ Driver Code Starts.
bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends