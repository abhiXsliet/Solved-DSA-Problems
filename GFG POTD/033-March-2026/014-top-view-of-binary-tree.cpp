// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1/



#include <bits/stdc++.h>
using namespace std;

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        //int-> Horizontal Dist, int -> Node*
        map<int, int> topNode;
        queue<pair <Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //if one value is present for a HD then do nothing
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode -> data;
            }
            
            if(frontNode -> left){
                q.push(make_pair(frontNode->left, hd-1));
            }
            
            if(frontNode -> right){
                q.push(make_pair(frontNode -> right, hd+1));
            }
        }
        
        for(auto i : topNode){
            ans.push_back(i.second);
        }
        return ans;
    }

};