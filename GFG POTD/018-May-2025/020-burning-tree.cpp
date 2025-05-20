// https://www.geeksforgeeks.org/problems/burning-tree/1




//User function Template for C++
class Solution {
    //create node to parent mapping
    //return target 
    Node* CreateParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
        
        Node* res = 0;
        
        queue<Node*>q;
        q.push(root);
        
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front -> data == target){
                res = front;
            }
            
            if(front -> left){
                nodeToParent[front -> left] = front;
                q.push(front -> left);
            }
            
            if(front -> right){
                nodeToParent[front -> right] = front;
                q.push(front -> right);
            }
        }
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent){
        
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root] = 1;
        
        int ans = 0;
        
        while(!q.empty()){
            
            bool flag = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                
                //process neighbouring nodes
                Node* front = q.front();
                q.pop();
                
                if(front -> left && !visited[front -> left]){
                    flag = 1;
                    q.push(front -> left);
                    visited[front -> left] = 1;
                }
                
                if(front -> right && !visited[front -> right]){
                    flag = 1;
                    q.push(front -> right);
                    visited[front -> right] = 1;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if(flag == 1){
             ans++;
            }
        }
        
        return ans;
    }
    
    void makeGraph(unordered_map<int, vector<int>>& adj, int parent, Node* curr) {
        if (curr == NULL) {
            return;
        }

        if (parent != -1) {
            adj[curr -> data].push_back(parent);
        }

        if (curr -> left) {
            adj[curr -> data].push_back(curr -> left -> data);
        }

        if (curr -> right) {
            adj[curr -> data].push_back(curr -> right -> data);
        }

        makeGraph(adj, curr -> data, curr -> left);
        makeGraph(adj, curr -> data, curr -> right);
    }
    
    int approach_1(Node* root, int target) {
        // Algo:
        //step 1 -> create a nodeToParent Mapping
        //step 2 -> find target node
        //step 3 -> burn the tree in min time
        
        map<Node*, Node*> nodeToParent;
        Node* targetNode = CreateParentMapping(root, target, nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        
        return ans;
    }
    
    // GRAPH TRAVERSAL : Two Times
    // T.C : O(n) - visiting all nodes
    // S.C : O(n) - storing all nodes in graph
    int approach_2(Node* root, int start) {
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);

        // Apply BFS From Start
        queue<int> que;
        unordered_set<int> vis;
        
        que.push(start);
        vis.insert(start);
        int minutes = 0;

        while (!que.empty()) {
            // current level size
            int n = que.size();
            while (n--) {
                int curr = que.front();
                que.pop();

                for (auto& neigh : adj[curr]) {
                    
                    if (vis.find(neigh) == vis.end()) {
                        que.push(neigh);
                        vis.insert(neigh);
                    }
                }
            }
            minutes ++;
        }

        return minutes-1;
    }

    // ONE PASS SOLUTION
    // TC : O(N)
    // SC : O(N)
    int approach_3(Node* root, int start, int& result) {
        if (root == NULL) {
            return 0;
        }

        int LH = approach_3(root -> left , start, result);
        int RH = approach_3(root -> right, start, result);

        if(root->data == start) {
            result = max(LH, RH);
            return -1;
        } else if(LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1;
        }
        
        return 0;   // flow not reach here
    }
  public:
    int minTime(Node* root, int target) 
    {
        // return approach_1(root, target);    // TLE
        
        return approach_2(root, target);

        // int result = INT_MIN;
        // approach_3(root, target, result);
        // return result;
    }
};