// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1



//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  private:
    void inorder(Node* root, unordered_set<int>& leaf, unordered_set<int>& non_leaf) {
        if (root == NULL) return;
        
        if (root -> left == NULL && root -> right == NULL) 
            leaf.insert(root -> data);
        else
            non_leaf.insert(root -> data);
        
        inorder(root -> left , leaf, non_leaf);
        inorder(root -> right, leaf, non_leaf);
    }
    
    // TC = O(N)
    // SC = O(N) -> External space used
    bool solve_approach_1(Node *root) {
        unordered_set<int> non_leaf;
        unordered_set<int> leaf;
        //insert 0 initially in non_leaf set
        non_leaf.insert(0);
        
        inorder(root, leaf, non_leaf);
        
        for (int i : leaf) {
            if ( (non_leaf.find(i + 1) != non_leaf.end()) && 
                 (non_leaf.find(i - 1) != non_leaf.end()) ) {
                
                return 1;     
            }
        }
        
        return 0;
    }
    
    // TC = O(N)
    // SC = O(N) -> Recursive Depth
    bool solve_approach_2(Node* root, int min, int max) {
        if(!root) return 0;
        
        if (root -> data == min && root -> data == max)
            return 1;
            
        return ( solve_approach_2(root -> left, min, root -> data - 1) ||
                 solve_approach_2(root -> right, root -> data + 1, max) );
    }
  public:
    bool isDeadEnd(Node *root)
    {
        // return solve_approach_1(root);
        
        return solve_approach_2(root, 1, 1e8); // given range is 1 to 10001
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends