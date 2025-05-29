// https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1




#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    typedef pair<int, int> P;
    
    // TC : O(N)
    // SC : O(H)
    P dfs(Node *root, int depth) {
        if (!root) {
            return {0, depth};
        }
        
        P L = dfs(root ->  left, depth + 1);
        P R = dfs(root -> right, depth + 1);
        
        if (L.second >= R.second) {
            if (L.second == R.second) {
                int val = L.first > R.first ? L.first : R.first;
                return {root -> data + val, R.second};
            }
            return {(root -> data + L.first), L.second};
        } 
        return {(root -> data + R.first), R.second};
    }
  public:
    // TC : O(N)
    // SC : O(1)
    int sumOfLongRootToLeafPath(Node *root) {
        return dfs(root, 0).first;
    }
};