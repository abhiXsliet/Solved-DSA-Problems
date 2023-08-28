// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
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
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.

// TC = O(N)
Node* solve_1(Node* head) {
    Node* prev = head;
    Node* curr = head -> next;
    while(curr != NULL) {
        if(prev -> data == curr -> data) {
            prev -> next = curr -> next;
        } else {
            prev = curr;
        }
        curr = curr -> next;
    }
    return head;
}

// TC = O(N)
Node* solve_2(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        while (temp -> next != NULL && temp -> data == temp -> next -> data) 
            temp -> next = temp -> next -> next;
        
        temp = temp -> next;
    }
    return head;
}

Node *removeDuplicates(Node *head)
{
    // return solve_1(head);
    
    return solve_2(head);
}