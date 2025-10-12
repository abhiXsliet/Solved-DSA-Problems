// https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1




#include <bits/stdc++.h>
using namespace std;

//User function Template for C++
struct Node {
	int data;
	Node *left, *right;
};

class Solution
{
    private:
    int solve(Node* root, int& moves) {
        if (!root) return 0;
        
        int l = solve(root -> left , moves);
        int r = solve(root -> right, moves);
        
        moves += abs(l) + abs(r);
        
        return (l + r + root -> data) - 1;
    }
    public:
    int distCandy(Node* root)
    {
        int moves = 0;
        solve(root, moves);
        return moves;
    }
};
