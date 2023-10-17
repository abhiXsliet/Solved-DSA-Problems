// https://leetcode.com/problems/validate-binary-tree-nodes/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> parent;
    int components;

    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    bool Union(int par, int child) {
        int child_ka_parent  = find(child);
    
        if(child_ka_parent != child)
            return false;
        
        int parent_ka_parent = find(par);

        if (parent_ka_parent == child_ka_parent) {
            return false;
        }
        
        parent[child] = par;
        components--;
        return true;
    }

    int bfs(int root, int n, unordered_map<int, vector<int>>& adj) {
        int cnt = 1;
        queue<int> que;
        vector<bool> vis(n, false);

        que.push(root);
        vis[root] = true;

        while(!que.empty()) {
            int node = que.front();
            que.pop();

            for (auto& i : adj[node]) {
                if (!vis[i]) {
                    vis[i] = true;
                    cnt++;
                    que.push(i);
                }
            }
        }
        return cnt;
    }

    int solve_approach_1(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>> parent_to_child;
        unordered_map<int, int> child_to_parent;

        // Step - 1: find the parent of each node and vice versa
        for (int i = 0; i < n; i++) {
            int node   = i;
            int leftC  = leftChild[i];
            int rightC = rightChild[i];

            if (leftC != -1) {
                parent_to_child[node].push_back(leftC);

                if (child_to_parent.find(leftC) != child_to_parent.end()) 
                    return false;

                child_to_parent[leftC] = node;
            }

            if (rightC != -1) {
                parent_to_child[node].push_back(rightC);

                if (child_to_parent.find(rightC) != child_to_parent.end()) 
                    return false;

                child_to_parent[rightC] = node;
            }
        }

        // Step - 2 : find the root value
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (child_to_parent.find(i) == child_to_parent.end()) {
                if (root != -1) return false;

                root = i;
            }
        }

        // if root is not present
        if (root == -1) return false;

        // Step - 3 : Start BFS to check the connected - only one component
        int count = bfs(root, n, parent_to_child);

        return count == n;
    }


    int solve_approach_2(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components = n;
        parent.resize(n);

        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            if (leftChild[i] >= 0 && !Union(i, leftChild[i])) {
                return false;
            }
            if (rightChild[i] >= 0 && !Union(i, rightChild[i])) {
                return false;
            }
        }
        
        return components == 1;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // return solve_approach_1(n, leftChild, rightChild);

        return solve_approach_2(n, leftChild, rightChild);
    }
};