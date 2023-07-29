#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data; 
    Node* prev;
    Node* next;

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node() {
        int value = this -> data;
        if(this -> next != NULL) {
            this -> next = NULL;
            delete next;
        }
        cout << "\nMemory is getting free with data " << value << endl;
    }
};

int getLength(Node* &head) {
    Node* temp = head;
    int length = 0;
    while(temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* node = new Node(data);
        head = node;
        tail = node;
    } else {
        Node* temp = new Node(data);
        head -> prev = temp;
        temp -> next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(tail == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(data);
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void insertAtPos(Node* &head, Node* &tail, int pos, int data) {
    if(pos == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    if(pos > getLength(head)+1) {
        cout << "Invalid position : " << pos 
        << "\nEnter the position considering the length of LL from 1 to " << getLength(head)+1 << endl; 
        cout << "\nFor now data will be inserted on tail\n";
        insertAtTail(head, tail, data);
        return ;
    } 

    Node* temp = head;
    Node* prev = NULL;

    int count = 1;
    while(count < pos-1) {
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

// deleting the node a/c given positions
void deleteAtPos(Node* &head, Node* &tail, int pos) {
    if(pos == 1) {
        Node* temp = head;
        head = temp -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
    } 
    else if(pos > getLength(head)+1) {
        cout << "\nInvalid position of deletion : " << pos 
        << "\nEnter position (<= length of LL) of range 1 to " << getLength(head) << endl;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;
        int count = 0;
        while(count < pos-1) {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        tail = prev;
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        while(tail -> next != NULL) {
            tail = tail -> next;
        }
        delete curr;
    }
}

int main() {
    
    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    insertAtHead(head, tail, 5);
    print(head);

    insertAtHead(head, tail, 4);
    print(head);
    
    insertAtTail(head, tail, 6);
    print(head);

    insertAtTail(head, tail, 8);
    print(head);

    insertAtPos(head, tail, 4, 7);
    print(head);

    cout << "\nLength of LL : " << getLength(head) << endl;

    insertAtPos(head, tail, 6, 10);
    print(head);

    insertAtPos(head, tail, 8, 20);
    print(head);
    
    deleteAtPos(head, tail, 1);
    print(head);

    deleteAtPos(head, tail, 3);
    print(head);

    deleteAtPos(head, tail, 5);
    print(head);

    deleteAtPos(head, tail, 15);
    print(head);

    cout << "\nHead is at : " << head -> data << endl;
    cout << "Tail is at : " << tail -> data << endl;

    cout << endl;
    return 0;
}