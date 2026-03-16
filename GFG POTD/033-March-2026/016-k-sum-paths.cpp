// https://www.geeksforgeeks.org/problems/k-sum-paths/1/




#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution { 
  private:
    // TC : O(N)
    // SC : O(H)
    int getCountOfPaths(Node *root, int k, int currSum) {
        if (!root) return 0;
        
        int pathCount = 0;
        
        currSum += root -> data;
        if (currSum == k) pathCount ++;

        int L = getCountOfPaths(root ->  left, k, currSum);
        int R = getCountOfPaths(root -> right, k, currSum);
        
        return pathCount + L + R;
    }

    // TC : O(N^2)
    // SC : O(1)
    int brute(Node *root, int k) {
        if (!root) return 0;
        // count all paths whose sum == k from root
        int paths = getCountOfPaths(root, k, 0);
        
        int L = brute(root ->  left, k);
        int R = brute(root -> right, k);
        
        return paths + L + R;
    }
    
    // TC : O(N)
    // SC : O(1)
    int optimal(Node *root, int k, unordered_map<int, int> &mpp, int currSum) {
        if (!root) return 0;
        
        int pathCount = 0;
        
        currSum += root -> data;

        pathCount += mpp[currSum - k];
        mpp[currSum] += 1;
        
        int L = optimal(root ->  left, k, mpp, currSum);
        int R = optimal(root -> right, k, mpp, currSum);
        
        mpp[currSum] -= 1;
        
        return pathCount + L + R;
    }
  public:
    int countAllPaths(Node *root, int k) {
        // return brute(root, k);   // Try making pathSum == k from every node
        
        unordered_map<int, int> mpp;  // track the currSum till a node with its occurances
        mpp[0] = 1;
        return optimal(root, k, mpp, 0);
    }
};
