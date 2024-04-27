// https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  private:
    // TC : O(N) Where N = No. Of Nodes
    // SC : O(1) 
    struct Node* getMiddle(struct Node* head) {
        struct Node* slow = head;
        struct Node* fast = head;
        
        while(fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    // TC : O(N + M) Where N = No. Of Nodes in 1st List & M = No. Of Nodes in 2nd List
    // SC : O(N) -> Recursive Depth
    struct Node* mergeRec(struct Node* first, struct Node* second) {
        if (!first) return second;
        if (!second) return first;

        if (first -> data < second -> data) {
            first -> next = mergeRec(first -> next, second);
            first -> next -> prev = first;
            first -> prev = NULL;
            return first;
        } else {
            second -> next = mergeRec(first, second -> next);
            second -> next -> prev = second;
            second -> prev = NULL;
            return second;
        }
    }
    
    // TC : O(N + M)
    // SC : O(1)
    struct Node* merge(struct Node* &left, struct Node* &right) {
        struct Node* mergedList = NULL;
        struct Node** current   = &mergedList;
        struct Node* prev = NULL;
    
        while(left != NULL && right != NULL) {
            if(left -> data <= right -> data) {
                *current = left;
                left = left -> next;
            } else {
                *current = right;
                right = right -> next;
            }
            (*current) -> prev = prev;
            prev = *current;
            current = &((*current) -> next);
        }
    
        while(left != NULL) {
            *current = left;
            left = left -> next;
            (*current) -> prev = prev;
            prev = *current;
            current = &((*current) -> next);
        } 
    
        while(right != NULL) {
            *current = right;
            right = right -> next;
            (*current) -> prev = prev;
            prev = *current;
            current = &((*current) -> next);
        }
    
        return mergedList;
    }
  public:
    // TC : O(N*Log(N))
    // SC : O(Log(N))   Where N = No. of Nodes
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        if (!head || !head -> next) return head;
        
        struct Node* middle  = getMiddle(head);
        struct Node* midNext = middle -> next;
        middle  -> next = NULL;
        midNext -> prev = NULL;
        
        struct Node* left  = sortDoubly(head);
        struct Node* right = sortDoubly(midNext);
        
        // return mergeRec(left, right);    // SC : O(Rec Depth)
        
        return merge(left, right);          // SC : O(1)
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends