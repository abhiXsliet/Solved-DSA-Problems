// https://www.geeksforgeeks.org/problems/linked-list-matrix/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};
// } Driver Code Ends

/*structure of the node of the linked list is as
struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  private:
    // TC : O(N^2)
    // SC : O(N^2)
    Node* approach_1(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Vector to store the head nodes of each row (initially all NULL)
        vector<Node*> heads(n, NULL);
        Node* mainHead = NULL;
        Node* temp     = NULL;
        
        // Traverse the matrix and create linked list nodes for each element
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                Node* newNode = new Node(mat[i][j]);
                
                if (!mainHead) {
                    mainHead = newNode;
                }
                
                if (!heads[i]) {
                    heads[i] = newNode;
                } else {
                    temp -> right = newNode;
                }
                
                temp = newNode;
            }
        }
        
        // Now link the 'down' pointers to connect rows
        for (int i = 0; i < n - 1; i ++) {
            Node* curr = heads[i];
            Node* next = heads[i + 1];
            while (curr && next) {
                curr -> down = next;
                curr = curr -> right;
                next = next -> right;
            }
        }
        
        return mainHead;
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    Node* approach_2(vector<vector<int>>& mat, int i, int j) {
        if (i >= mat.size() || j >= mat.size())
            return NULL;
            
        Node* curr    = new Node(mat[i][j]);
        curr -> right = approach_2(mat, i, j + 1);
        curr -> down  = approach_2(mat, i + 1, j);
        
        return curr;
    }
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // return approach_1(mat);  // Iterative
        
        return approach_2(mat, 0, 0);  // Recursive
    }
};


//{ Driver Code Starts.
void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code End