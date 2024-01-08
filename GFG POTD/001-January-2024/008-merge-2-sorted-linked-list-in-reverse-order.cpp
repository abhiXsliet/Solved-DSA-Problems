// https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    private:
    // TC : O(N)
    // SC : O(1)
    struct Node* reverse(Node* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        else {
            Node* prev = NULL;
            Node* curr = head;
            Node* forw = NULL;
            
            while (curr != NULL) {
                forw = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forw;
            }
            return prev;
        }
    }
    
    // Recursive Approach
    // TC : O(M + N) Where M = No. of nodes in node1 & N = No. of nodes in node2
    // SC : O(M + N) -> Recursive Depth
    struct Node* solve_approach_1(Node* node1, Node* node2) {
        if (node1 == NULL) return node2;
        if (node2 == NULL) return node1;
        
        if (node1 -> data <= node2 -> data) {
            node1 -> next = solve_approach_1(node1 -> next, node2);
            return node1;
        }
        else {
            node2 -> next = solve_approach_1(node1, node2 -> next);
            return node2;
        }
    }
    
    // TC : O(N + M)
    // SC : O(1)
    struct Node* solve_2(Node* node1, Node* node2) {
        if (node1 -> next == NULL) {    // if only 1-Node is present in 1st-list
            node1 -> next = node2;
            return node1;
        }
        
        Node* curr1 = node1;
        Node* next1 = curr1 -> next;
        Node* curr2 = node2;
        Node* next2 = curr2 -> next;
        
        while (next1 != NULL && curr2 != NULL) {
            if ((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)) {
                // adding nodes b/w the nodes of first list
                curr1 -> next = curr2;
                next2 = curr2 -> next;
                curr2 -> next = next1;
                
                curr1 = curr2;
                curr2 = next2;
            }
            else {
                // move a step ahead in first list
                curr1 = next1;
                next1 = next1 -> next;
                
                if (next1 == NULL) {
                    curr1 -> next = curr2;
                    return node1;
                }
            }
        }
        
        return node1;
    }
    
    // Iterative Approach
    struct Node* solve_approach_2(Node* node1, Node* node2) {
        if (node1 == NULL) return node2;
        if (node2 == NULL) return node1;
        
        if (node1 -> data <= node2 -> data) {
            return solve_2(node1, node2);
        }
        else {
            return solve_2(node2, node1);
        }
    }
    
    public:
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // return reverse(solve_approach_1(node1, node2));
        
        
        return reverse(solve_approach_2(node1, node2));
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends