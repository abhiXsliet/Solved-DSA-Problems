// https://www.geeksforgeeks.org/problems/clone-graph/1



//{ Driver Code Starts
//Initial Template for C++

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
vector<Node*> bfs(Node *src){
    vector<Node*>ans;
    map<Node*, bool> visit;
    queue<Node*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty()) {
        Node *u = q.front();
        ans.push_back(u);
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++){
            if (!visit[v[i]]){
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    return ans;
}

bool compare(Node* prev, Node* new_node, unordered_set<Node*>& prev_vis, unordered_set<Node*>& new_vis) {
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
        if ((prev_vis.count(prev) && !new_vis.count(new_node)) || (!prev_vis.count(prev) && new_vis.count(new_node))) {
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

    sort(prev->neighbors.begin(), prev->neighbors.end(), [](Node* a, Node* b) { return a->val < b->val; });
    sort(new_node->neighbors.begin(), new_node->neighbors.end(), [](Node* a, Node* b) { return a->val < b->val; });

    for (size_t i = 0; i < prev_n; ++i) {
        if (!compare(prev->neighbors[i], new_node->neighbors[i], prev_vis, new_vis)) {
            return false;
        }
    }

    return true;
}


// } Driver Code Ends
//User function Template for C++

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
    // TC : O(N)
    // SC : O(Depth) ~= O(N)
    void DFS(Node* node, Node* clone_node, unordered_map<Node*, Node*>& mpp) {
        for (auto& originalNeigh : node -> neighbors) {
            
            if (mpp.find(originalNeigh) == mpp.end()) {
                
                Node* clone_neigh   = new Node(originalNeigh -> val);
                mpp[originalNeigh]  = clone_neigh;
                clone_node -> neighbors.push_back(clone_neigh);
                
                DFS(originalNeigh, clone_neigh, mpp);
            }
            else {
                clone_node -> neighbors.push_back(mpp[originalNeigh]);
            }
        }
    }
    
    // TC : O(N)
    // SC : O(N) -> Space Used by queue
    void BFS(Node* node, Node* clone_node, unordered_map<Node*, Node*>& mpp) {
        queue<Node*> q;
        
        q.push(node);
        
        while(!q.empty()) {
            
            Node* frontNode  = q.front();
            Node* clone_node = mpp[frontNode];
            q.pop();
            
            for (auto& original_neigh : frontNode -> neighbors) {
                
                if (mpp.find(original_neigh) == mpp.end()) {
                    
                    Node* clone_neigh   = new Node(original_neigh -> val);
                    mpp[original_neigh] = clone_neigh;
                    clone_node -> neighbors.push_back(clone_neigh);
                    
                    q.push(original_neigh);
                }
                else {
                    clone_node -> neighbors.push_back(mpp[original_neigh]);
                }
            }
        }
    }
    
    // TC : O(N + E) Where N = No. Of Nodes & E = No. Of Edges
    // SC : O(N) -> Map
    Node* solve_approach_1(Node* node) {
        if (!node) return NULL;
        
        unordered_map<Node*, Node*> mpp; // {old_node, clone_node}
        
        Node* clone_node = new Node(node -> val);
        mpp[node] = clone_node;
        
        DFS(node, clone_node, mpp);
        
        return clone_node;
    }
    
    // TC : O(N + E) Where N = No. Of Nodes & E = No. Of Edges
    // SC : O(N) -> Map
    Node* solve_approach_2(Node* node) {
        if (!node) return NULL;
        
        unordered_map<Node*, Node*> mpp; // {old_node, clone_node}
        
        Node* clone_node = new Node(node -> val);
        mpp[node] = clone_node;
        
        BFS(node, clone_node, mpp);
        
        return clone_node;
    }
    
    // TC : O(N)
    // SC : O(N) -> Space Used By Queue
    // At Worst, if all nodes are connected to the root node, 
    // the maximum size of the queue could be N
    void BFS_2(Node* node, Node* clone_node, vector<Node*>& store) {
        queue<Node*> q;
        
        q.push(node);
        
        while(!q.empty()) {
            
            Node* frontNode  = q.front();
            Node* clone_node = store[frontNode -> val];
            q.pop();
            
            for (auto& original_neigh : frontNode -> neighbors) {
                
                if (store[original_neigh -> val] == NULL) {
                    
                    Node* clone_neigh     = new Node(original_neigh -> val);
                    store[original_neigh -> val] = clone_neigh;
                    clone_node -> neighbors.push_back(clone_neigh);
                    
                    q.push(original_neigh);
                }
                else {
                    clone_node -> neighbors.push_back(store[original_neigh -> val]);
                }
            }
        }
    }
    
    // TC : O(N + E) Where N = No. Of Nodes & E = No. Of Edges
    // SC : O(10001) ~= O(N)
    Node* solve_approach_3(Node* node) {
        if (!node) return NULL;
         
        // store[0] = Node
        // 0 value wale original node ka clone node = Node at store[0]
        vector<Node*> store(10001, NULL);
        
        Node* clone_node   = new Node(node -> val);
        store[node -> val] = clone_node;
        
        BFS_2(node, clone_node, store);
        
        return clone_node;
    }
public:
    Node* cloneGraph(Node* node) {
        // return solve_approach_1(node);
        
        // return solve_approach_2(node);
        
        return solve_approach_3(node);
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
        vector<Node*>v(N);
        std::string buffer;
        std::getline(std::cin, buffer);
        for (int i = 0; i < N; i++)v[i] = new Node(i);
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
        vector<Node*>prev = bfs(v[0]);
        Node* ans = ob.cloneGraph(v[0]);
        //vector<Node*>now = bfs(ans);
        unordered_set<Node*>prev_vis, new_vis;
        cout << compare(v[0], ans, prev_vis, new_vis) << endl;

    }
    return 0;
}
// } Driver Code Ends