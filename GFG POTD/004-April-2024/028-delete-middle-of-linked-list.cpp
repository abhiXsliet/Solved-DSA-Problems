// https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1



//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
struct Node {
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
// } Driver Code Ends

/* Link list Node:
struct Node {
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Deletes middle of linked list and returns head of the modified list
class Solution{
    private:
    // TC : O(N)
    // SC : O(1)    
    Node* getMiddle(Node* head, Node* &prev) {
        Node* slow = head;
        Node* fast = head;
        while(fast -> next && fast -> next -> next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    // TC : O(N)
    // SC : O(1)
    Node* solve_brute(Node* head) {
        if (!head -> next) return head -> next;
        if (!head -> next -> next) {
            head -> next = NULL;
            return head;
        }
        
        int cnt = 0;
        Node* temp = head;
        while(temp) {
            cnt += 1;
            temp = temp -> next;
        }
        
        Node* prev    = NULL;
        Node* midNode = getMiddle(head, prev);

        // If Node cnt is Even
        if (cnt % 2 == 0) {
            prev = prev -> next;
            midNode = midNode -> next;
        }
        
        prev -> next    = midNode -> next;
        midNode -> next = NULL;
        return head;
    }

    // TC : O(N)
    // SC : O(1)
    Node* getMid(Node* head, Node* &prev) {
        Node* slow = head;
        Node* fast = head;
        while(fast && fast -> next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    // TC : O(N)
    // SC : O(1)
    Node* solve_better(Node* head) {
        if (!head -> next) return NULL;
        
        Node* prev    = NULL;
        Node* midNode = getMid(head, prev);

        if (prev) prev -> next = midNode -> next;
        
        delete midNode;
        return head;
    }
    public:
    Node* deleteMid(Node* head) {
        // return solve_brute(head);   // Double Traversal of LL
                                    
        return solve_better(head);  // Single Traversal of LL
    }
};


//{ Driver Code Starts.
void printList(Node* node)  { 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 

int main() { 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
		printList(head); 
	}
	return 0; 
} 
// } Driver Code Ends