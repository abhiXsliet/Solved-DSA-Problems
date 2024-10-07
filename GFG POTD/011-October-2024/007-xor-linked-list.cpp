// https://www.geeksforgeeks.org/problems/xor-linked-list/1



//{ Driver Code Starts
#include <stdint.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> getList(struct Node *head);

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        struct Node *head = NULL;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            head = insert(head, number);
        }

        vector<int> vec = getList(head);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// TC : O(1)
// SC : O(1)
// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    Node* newNode = new Node(data);
    
    /* Since new node is being inserted at the 
    beginning, npx of new node will always be 
    XOR of current head and NULL */
    newNode -> npx = head;
    
    /* If linked list is not empty, then npx of 
    current head node will be XOR of new node 
    and node next to current head */
    if (head) {
        // head->npx is XOR of NULL and next. 
        // So if we do XOR of it with NULL, we get next 
        head -> npx = XOR(newNode, head -> npx);
    }
    
    head = newNode;
}

// TC : O(N)
// SC : O(1)
vector<int> getList(struct Node *head) {
    Node* curr = head;
    Node* prev = NULL;
    vector<int> res;
    while (curr) {
        res.push_back(curr -> data);
        Node* next = XOR(prev, curr -> npx);
        
        prev = curr;
        curr = next;
    }
    return res;
}
