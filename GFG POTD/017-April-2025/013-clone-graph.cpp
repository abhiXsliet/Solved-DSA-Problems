// https://www.geeksforgeeks.org/problems/clone-graph/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

vector<Node*> bfs(Node* src) {
    vector<Node*> ans;
    map<Node*, bool> visit;
    queue<Node*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty()) {
        Node* u = q.front();
        ans.push_back(u);
        q.pop();
        vector<Node*> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (!visit[v[i]]) {
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    return ans;
}

bool compare(Node* prev, Node* new_node, unordered_set<Node*>& prev_vis,
             unordered_set<Node*>& new_vis) {
    if (prev == new_node) {
        return false;
    }
    if (!prev || !new_node) {
        if ((!prev && new_node) || (prev && !new_node)) {
            return false;
        }
        return true;
    }

    if (prev_vis.count(prev) || new_vis.count(new_node)) {
        if ((prev_vis.count(prev) && !new_vis.count(new_node)) ||
            (!prev_vis.count(prev) && new_vis.count(new_node))) {
            return false;
        }
        return true;
    }
    prev_vis.insert(prev);
    new_vis.insert(new_node);

    if (prev->val != new_node->val) {
        return false;
    }

    size_t prev_n = prev->neighbors.size();
    size_t new_n = new_node->neighbors.size();
    if (prev_n != new_n) {
        return false;
    }

    sort(prev->neighbors.begin(), prev->neighbors.end(),
         [](Node* a, Node* b) { return a->val < b->val; });
    sort(new_node->neighbors.begin(), new_node->neighbors.end(),
         [](Node* a, Node* b) { return a->val < b->val; });

    for (size_t i = 0; i < prev_n; ++i) {
        if (!compare(prev->neighbors[i], new_node->neighbors[i], prev_vis, new_vis)) {
            return false;
        }
    }

    return true;
}
// } Driver Code Ends

// User function Template for C++
// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  private:
    void bfs(Node* node, Node* clone, unordered_map<Node*, Node*> &visited) {
        queue<pair<Node*, Node*>> q;
        q.push({node, clone});
        while (!q.empty()) {
            Node* fNode = q.front().first;
            Node* cNode = q.front().second;
            q.pop();
            
            for (auto &nbr : fNode -> neighbors) {
                if (!visited.count(nbr)) {
                    Node* cloneNbr = new Node(nbr -> val);
                    visited[nbr] = cloneNbr;
                    cNode -> neighbors.push_back(cloneNbr);
                    q.push({nbr, cloneNbr});
                } else {
                    cNode -> neighbors.push_back(visited[nbr]);
                }
            }   
        }
    }
    
    void dfs(Node* node, Node* clone, unordered_map<Node*, Node*> &visited) {
        for (auto &nbr : node -> neighbors) {
            if (!visited.count(nbr)) {
                Node* cloneNbr = new Node(nbr -> val);
                visited[nbr] = cloneNbr;
                clone -> neighbors.push_back(cloneNbr);
                dfs(nbr, cloneNbr, visited);
            } else {
                clone -> neighbors.push_back(visited[nbr]);
            }
        }
    }
    
    // TC : O(V + E)
    // SC : O(V)
    Node* approach_1(Node* node) {
        unordered_map<Node*, Node*> visited;
        
        Node* clone = new Node(node -> val);
        visited[node] = clone;

        dfs(node, clone, visited);
        
        return clone;
    }

    // TC : O(V + E)
    // SC : O(V)
    Node* approach_2(Node* node) {
        unordered_map<Node*, Node*> visited;
        
        Node* clone = new Node(node -> val);
        visited[node] = clone;

        bfs(node, clone, visited);
        
        return clone;
    }
  public:
    Node* cloneGraph(Node* node) {
        // return approach_1(node); // DFS
        return approach_2(node); // BFS
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Node* root = NULL;
        vector<Node*> v(N);
        std::string buffer;
        std::getline(std::cin, buffer);
        for (int i = 0; i < N; i++)
            v[i] = new Node(i);
        for (int i = 0; i < N; i++) {
            std::vector<Node*> vec;
            std::string buffer;
            int data;
            std::getline(std::cin, buffer);
            std::istringstream iss(buffer);
            while (iss >> data)
                vec.push_back(v[data]);
            v[i]->neighbors = vec;
        }
        Solution ob;
        vector<Node*> prev = bfs(v[0]);
        Node* ans = ob.cloneGraph(v[0]);
        // vector<Node*>now = bfs(ans);
        unordered_set<Node*> prev_vis, new_vis;
        if (compare(v[0], ans, prev_vis, new_vis))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends