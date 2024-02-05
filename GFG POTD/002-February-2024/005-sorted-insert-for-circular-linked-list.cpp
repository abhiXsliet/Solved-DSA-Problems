// https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1




//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};


// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    private:
    // TC : O(N)
    Node* solve_approach_1(Node* head, int d) {
        if(head == NULL) {
            Node* newNode = new Node(d);
            return newNode -> next = newNode;
        }
        
        Node* curr = head;
        Node* prev = NULL;
        
        if (head -> data <= d) {
            while (curr -> data <= d) {
                prev = curr;
                curr = curr -> next;
                if (curr == head) 
                    break;
            }
            
            Node* nodeToInsert = new Node(d);
            prev -> next = nodeToInsert;
            nodeToInsert -> next = curr;
        }
        else if (head -> data > d) {
            Node* nodeToInsert = new Node(d);
            prev = nodeToInsert;
            prev -> next = curr;
            
            while(curr -> next != head) {
                curr = curr -> next;
            }
            
            curr -> next = prev;
            head = prev;
        }
        return head;
    }
    
    // TC : O(N)
    Node* solve_approach_2(Node* head, int data) {
        if (head == NULL) {
            Node* newNode = new Node(data);
            newNode->next = newNode; 
            return newNode;
        }
        
        Node* curr = head;
        Node* pre = NULL;
    
        if (head->data > data) {
            while (curr->next != head) {
                curr = curr->next;
            }
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
            curr->next = temp;
        } else {
            while (curr->data <= data) {
                pre = curr;
                curr = curr->next;
                if (curr == head) {
                    break;
                }
            }
            Node* temp = new Node(data);
            temp->next = curr;
            pre->next = temp;
        }
    
        return head;

    }
    public:
    Node *sortedInsert(Node* head, int data) {
        // return solve_approach_1(head, data);
        
        return solve_approach_2(head, data);
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}
/* Driver program to test above functions */
int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;
  
  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;
  
  
    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);
    
    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }
    
    if(n>0)
    temp->next=start;
 
    scanf("%d",&x);
    Solution ob;
    start = ob.sortedInsert(start,x);
    printList(start);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
}
  return 0;
}

// } Driver Code Ends