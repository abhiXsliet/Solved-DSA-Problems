// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/




#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this -> data  = d;
        this -> left  = nullptr;
        this -> right = nullptr;
    }
};

//Function to return a list containing the bottom view of the given tree.
class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    vector<int> bottomView(Node *root) {
        map<int, int> mpp;    // {HD, Node}
        queue<pair<Node*, int>> q;  // {Node, HD}
        
        q.push({root, 0});
        while (!q.empty()) {
            Node* frontN  = q.front().first;
            int horizDist = q.front().second;
            q.pop();
            
            mpp[horizDist] = frontN -> data;
            
            if (frontN -> left) 
                q.push({frontN -> left, horizDist - 1});
            
            if (frontN -> right)
                q.push({frontN -> right, horizDist + 1});
        }
            
        vector<int> result;
        for (auto& node : mpp) {
            result.push_back(node.second);
        }
        return result;
    }
};