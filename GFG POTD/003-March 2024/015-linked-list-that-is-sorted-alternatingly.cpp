// https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution {
    private:
    // TC : O(N)
    // SC : O(N) Where N = No. of Nodes
    void approach_1(Node **head) {
        multiset<int> st;
        Node* temp = *head;
        while(temp != NULL) {
            st.insert(temp -> data);
            temp = temp -> next;
        }
        temp = *head;
        for (auto& it : st) {
            temp -> data = it;
            temp = temp -> next;
        }
    }
    
    // TC : O(N + M) ~= O(N)
    // SC : O(1) 
    Node* merge(Node* h1, Node* h2) {
        Node* dummy = new Node(0);
        Node* curr  = dummy;
        
        while (h1 != NULL && h2 != NULL) {
            if (h1 -> data < h2 -> data) {
                curr -> next = h1;
                h1 = h1 -> next;
            }
            else {
                curr -> next = h2;
                h2 = h2 -> next;
            }
            curr = curr -> next;
        }
        
        if (h1 != NULL) {
            curr -> next = h1;
        }
        else {
            curr -> next = h2;
        }
        
        return dummy -> next;
    }
    
    // TC : O(N)
    // SC : O(1)
    void reverse(Node** head) {
        Node* prev = NULL;
        Node* curr = *head;
        Node* forward;
        while (curr != NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        *head = prev;
    }
    
    // TC : O(N)
    // SC : O(1) Where N = No. of Nodes
    void approach_2(Node **head) {
        Node* h1 = new Node(-1);
        Node* h2 = new Node(-1);
        
        Node* temp1 = h1;
        Node* temp2 = h2;
        Node* curr  = *head;
        
        while (curr != NULL) {
            temp1 -> next = curr;
            temp1 = temp1 -> next;
            curr  = curr -> next;
            
            if (curr != NULL) {
                temp2 -> next = curr;
                temp2 = temp2 -> next;
                curr  = curr -> next;
            }
            
            temp1 -> next = NULL;
            temp2 -> next = NULL;
        }
        
        h1 = h1 -> next;
        h2 = h2 -> next;
    
        reverse(&h2);
        
        *head = merge(h1, h2);
    }
    public:
    // your task is to complete this function
    void sort(Node **head) {
        // return approach_1(head);
        
        return approach_2(head);
    }
};


//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends