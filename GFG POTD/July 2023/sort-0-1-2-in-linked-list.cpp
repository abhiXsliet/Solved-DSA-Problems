// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1




//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    // TC => O(N)
    // SC => O(1)
    Node* segregate(Node *head) {
/* 
        // Approach - 1
        Node* temp = head;
        int cntZero = 0;
        int cntOne = 0;
        int cntTwo = 0;
        while(temp != NULL) {
            if(temp -> data == 0) cntZero ++;
            else if(temp -> data == 1) cntOne ++;
            else cntTwo ++;
            temp = temp -> next;
        }
        temp = head;
        while(cntZero--) {
            temp -> data = 0;
            temp = temp -> next;
        }
        while(cntOne--) {
            temp -> data = 1;
            temp = temp -> next;
        }
        while(cntTwo--) {
            temp -> data = 2;
            temp = temp -> next;
        }
        return head;
        
         */
        
        
        // Approach - 2
        Node* temp = head;
        int size = 3;
        int count[size] = {0};
        while(temp != NULL) {
            count[temp -> data]++;
            temp = temp -> next;
        }
        temp = head;
        for(int i = 0; i < size; i++) {
            while(count[i]--) {
                temp -> data = i;
                temp = temp -> next;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends