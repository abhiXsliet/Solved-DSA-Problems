// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/




#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int, vector<int>> mpp;
        queue<pair<Node*, int>> q;
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            mpp[hd].push_back(frontNode -> data);
            
            if(frontNode -> left)
                q.push({frontNode -> left, hd - 1});
                
            if(frontNode -> right)
                q.push({frontNode -> right, hd + 1});
        }
        
        for (auto &it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};