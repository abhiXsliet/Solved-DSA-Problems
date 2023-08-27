// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-117/problems



//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
private:
    int cal_1(vector<int>& list, int key) {
        int a = -1, b = -1;
        if (list.size() == 1) return list[0]/2;
        
        int d1 = INT_MAX, d2 = INT_MAX;
        for(int i = 0; i < list.size(); i++){
            if (list[i] == key) return list[i];
            int diff = abs(list[i] - key);
            if(list[i] < key){
                if(d1 > diff) {
                    a=list[i];
                    d1=diff;
                }
            }
            if(list[i]>key){
                if(d2 > diff){
                    b=list[i];
                    d2=diff;
                }
            }
           
        }
        
        if (a == -1 && b == -1) {
            return 0;
        }
        return (int) ceil((a + b) / 2.0);
    }

    int findLowerBound(vector<int>& list, int key) {
        int left = 0, right = list.size() - 1, index1 = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid] <= key) {
                index1 = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return index1;
    }
    
    int findUpperBound(vector<int>& list, int key) {
        int left = 0, right = list.size() - 1, index2 = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid] >= key) {
                index2 = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return index2;
    }
    
    int cal_2(vector<int>& list, int key) {
        int index1 = findLowerBound(list, key);
        int index2 = findUpperBound(list, key);
        
        if (index1 == -1 && index2 == -1) return 0;
        
        int a = -1,b = -1;
        if(index1 != -1) a = list[index1];
        if(index2 != -1) b = list[index2];
        return (int)ceil((a + b) / 2.0);
    }
    
    void solve(Node* root, vector<int>& store) {
        if (!root)
            return;

        solve(root->left, store);
        store.push_back(root->data); 
        solve(root->right, store);
    }
    
public:
    int mean(Node* root, int key){
        vector<int> store;
        solve(root, store);
        
        return cal_1(store, key);
        
        // better
        // return cal_2(store, key);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int key;
        cin >> key;
        Solution ob;
        cout<<ob.mean(root, key)<<endl;
        cin.ignore();
    }
    return 0;
}
// } Driver Code Ends