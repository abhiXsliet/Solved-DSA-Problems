// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
    Node *reverse(Node *head) {
        
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL) {
            Node* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    Node* solve(Node* head) {
        Node* prev = head;
        Node* curr = head -> next;
        
        while(curr != NULL) {
            if(prev -> data > curr -> data) {
                prev -> next = curr -> next;
            } else {
                prev = prev -> next;
            }
            curr = curr -> next;
        }
        return head;
    }
    
    public:
    Node *compute(Node *head)
    {
        Node* reversed = reverse(head);
        
        return reverse(solve(reversed));
    }
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends