#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data; 
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this -> data;
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "\nMemory is getting free from node with data: " << value << endl;
    }
};

int getLength(Node* head) {
    Node* temp = head;
    int length = 1;
    while(temp -> next != NULL) {
        length++;
        temp = temp -> next;
    }
    return length;
}

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtPos(Node* &head, Node* &tail, int pos, int data) {
    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    if(pos > getLength(head)+1) {
        cout << "\nInvalid position of insertion so inserting " << data << " at tail" << endl;
        insertAtTail(tail, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < pos-1) {
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL || temp == NULL) {
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteAtPosition(Node* &head, Node* &tail, int pos) {
    if(pos == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    } 
    else {
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < pos) {
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        // cout << prev -> data << endl;
        if(prev -> next == NULL) {
            tail = prev;
        }
    }
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node* node = new Node(10);
    cout << node -> data << endl;
    cout << node -> next << endl;
    
    Node* head = node;
    Node* tail = node;
    print(head); 

    insertAtHead(head, 5);
    print(head);

    insertAtTail(tail, 20);
    print(head);

    insertAtPos(head, tail, 1, 2);
    print(head);

    insertAtPos(head, tail, 3, 7);
    print(head);

    cout << "\nLength of LL : "<< getLength(head) << endl << endl;
    
    insertAtPos(head, tail, 6, 25);
    print(head);
    
    insertAtPos(head, tail, 17, 50);
    print(head);

    deleteAtPosition(head, tail, 1);
    print(head);

    deleteAtPosition(head, tail, 4);
    print(head);
    
    cout << "\nLength of LL : "<< getLength(head) << endl;

    deleteAtPosition(head, tail, 5);
    print(head);

    cout << endl;
    cout << "Head is at : " << head -> data << endl;
    cout << "Tail is at : " << tail -> data << endl;
    
    cout << endl;
    return 0;
}