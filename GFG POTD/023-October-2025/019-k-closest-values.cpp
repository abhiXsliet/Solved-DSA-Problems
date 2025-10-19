// https://www.geeksforgeeks.org/problems/k-closest-values/1/




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
  private:
    using P = pair<int, int>;
    template <typename PQ>
    
    void solve(Node *root, int tar, PQ &pq) {
        if (!root) return;
        
        solve(root -> left, tar, pq);
        
        pq.push({abs(root -> data - tar), root -> data});
        
        solve(root -> right, tar, pq);
    }
  public:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> getKClosest(Node* root, int target, int k) {
        auto cmp = [&](P a, P b) {
            if (a.first == b.first) {
                return b.second < a.second;
            }  
            return a.first > b.first;
        };
        priority_queue<P, vector<P>, decltype(cmp)>pq(cmp);
        
        solve(root, target, pq);
        
        vector<int> result;
        while (!pq.empty() && k --) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};