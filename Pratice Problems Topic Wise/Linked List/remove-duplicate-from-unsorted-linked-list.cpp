#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int d) {
            this -> data = d;
            this -> next = NULL;
        }

        ~Node() {
            int val = this -> data;
            if( this -> next != NULL ) {
                this -> next = NULL;
                delete next;
            }
            cout << "\nMemory is getting free of Node with data " << val << endl;
        }
};
void createNode(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while(current -> next != NULL) {
            current = current -> next;
        }
        current -> next = newNode;
    }
}

void print(Node* &head) {
    Node* current = head;
    while(current != NULL) {
        cout << current -> data << " -> " ;
        current = current -> next;
    }
    if(head == NULL) cout << "\nNothing to print head is NULL" << endl;
    cout << endl;
}

Node* getMiddle(Node* &head) {
    if(head == NULL || head -> next == NULL) return head;

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

// The double pointer-to-pointer 'current' keeps track of the next pointer of the node in the merged list. 
// It allows us to update next pointers efficiently, modify the linked list in place without creating new nodes, 
// and achieve a space complexity of O(1) for the merge operation.

// TC : O(N1 + N2) => O(N)
Node* merge(Node* &left, Node* &right) {
    Node* mergedList = NULL;
    Node** current = &mergedList;

    while(left != NULL && right != NULL) {
        if(left -> data <= right -> data) {
            *current = left;
            left = left -> next;
        }else {
            *current = right;
            right = right -> next;
        }
        current = &((*current) -> next);
    }

    if(left != NULL) {
        *current = left;
        left = left -> next;
    } 
    if(right != NULL) {
        *current = right;
        right = right -> next;
    }

    return mergedList;
}

// TC : O(N * log(N))
// SC : O(log(N)) due to maximum depth of recursive calls stack
Node* mergeSort(Node* &head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* middle = getMiddle(head);
    Node* middleNext = middle -> next;
    middle -> next =  NULL;

    Node* left = mergeSort(head);
    Node* right = mergeSort(middleNext);

    return (merge(left, right));
}



// TC : O(N)
// SC : O(1)
Node* removeDuplicate_usingMergeSort(Node* &head) {
    if(head == NULL || head -> next == NULL) return head;

    Node* temp = head;
    while(temp != NULL && temp -> next != NULL) {

        if(temp -> data == temp -> next -> data) {
            Node* duplicateNode = temp -> next;
            temp -> next = temp -> next -> next;
            delete duplicateNode;

        } else {
            temp = temp -> next;
        }
    }
    return head;
}

// TC => O(N)
// SC => O(N)
Node * removeDuplicates( Node *head) 
{
    map<int, bool> mpp;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        
        if(mpp[temp -> data]) {
            Node* node = temp;
            prev -> next = temp -> next;
            temp = temp -> next;
            node -> next = NULL;
            delete node;
            
        } else {
            mpp[temp -> data] = 1;
            prev = temp;
            temp = temp -> next;
        }
    }
    return head;
}

int main() {

    Node* head = NULL;
    createNode(head, 7);  
    createNode(head, 7);
    createNode(head, 1);
    createNode(head, 6);
    createNode(head, 10);
    createNode(head, 2);
    createNode(head, 7);
    createNode(head, 4);
    createNode(head, 7);
    createNode(head, 6);
    print(head);

    Node* sort = mergeSort(head);
    print(sort);

    Node* removeDuplicate = removeDuplicate_usingMergeSort(sort);
    print(removeDuplicate);

    cout << endl;
    return 0;
}