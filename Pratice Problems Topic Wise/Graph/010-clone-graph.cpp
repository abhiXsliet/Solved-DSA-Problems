// https://leetcode.com/problems/clone-graph/



#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
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


class Solution {
private:
    // TC : O(N)
    // SC : O(Depth) ~= O(N)
    // At worst case, if graph is a linked list, the maximum depth of recursive call could be O(N)
    void DFS(Node* node, Node* clone_node, unordered_map<Node*, Node*>& mpp) {
        for (auto& original_neigh : node -> neighbors) {
            
            if (mpp.find(original_neigh) == mpp.end()) {
                
                Node* clone_neigh    = new Node(original_neigh -> val);
                mpp[original_neigh]  = clone_neigh;
                clone_node -> neighbors.push_back(clone_neigh);
                
                DFS(original_neigh, clone_neigh, mpp);
            }
            else {
                clone_node -> neighbors.push_back(mpp[original_neigh]);
            }
        }
    }

    // TC : O(N)
    // SC : O(N) -> Space Used By Queue
    // At Worst, if all nodes are connected to the root node, 
    // the maximum size of the queue could be N
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

    // TC : O(N + E) Where N = No. of Nodes & E = No. of Edges in graph
    // SC : O(N)
    Node* approach_1(Node* node) {
        if (!node) return NULL;

        unordered_map<Node*, Node*> mpp; // {old_node, clone_node}
        
        Node* clone_node = new Node(node -> val);
        mpp[node] = clone_node;
        
        DFS(node, clone_node, mpp);
        
        return clone_node;
    }
    
    // TC : O(N + E) Where N = No. Of Nodes & E = No. Of Edges
    // SC : O(N) -> Map
    Node* approach_2(Node* node) {
        if (!node) return NULL;
        
        unordered_map<Node*, Node*> mpp; // {old_node, clone_node}
        
        Node* clone_node = new Node(node -> val);
        mpp[node] = clone_node;
        
        BFS(node, clone_node, mpp);
        
        return clone_node;
    }
    
    // TC : O(N + E) Where N = No. Of Nodes & E = No. Of Edges
    // SC : O(1)
    Node* approach_3(Node* node) {
        if (!node) return NULL;
         
        // store[0] = Node
        // 0 value wale original node ka clone node = Node at store[0]
        vector<Node*> store(101, NULL);
        
        Node* clone_node   = new Node(node -> val);
        store[node -> val] = clone_node;
        
        BFS_2(node, clone_node, store);
        
        return clone_node;
    }
public:
    Node* cloneGraph(Node* node) {
        // return approach_1(node);

        // return approach_2(node);

        return approach_3(node);
    }
};