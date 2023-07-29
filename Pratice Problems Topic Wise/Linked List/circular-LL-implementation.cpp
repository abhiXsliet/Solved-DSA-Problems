#include <bits/stdc++.h>
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
        int value = this -> data;
        if(this -> next != NULL) {
            this -> next = NULL;
            delete next;
        }
        cout << "\nMemory is getting free from the Node with data : " << value << endl;
    }
};

void insertInCLL(Node* &tail, int data, int searchData) {
    if(tail == NULL) {
        Node* temp = new Node(data);
        tail = temp;
        tail -> next = temp;
    } 
    else {
        //Assume that the data is present in the linked list
        Node* temp = tail;
        while(temp -> data != searchData) {
            temp = temp -> next;
        }

        Node* nodeToInsert = new Node(data);
        nodeToInsert -> next = temp -> next;
        temp -> next = nodeToInsert;
    }
}

void deleteInCLL(Node* &tail, int deleteData) {
    if(tail == NULL) {
        cout << "\nNothing is available to delete" << endl;
    } else {
        Node* prev = tail;
        Node* curr = tail -> next;
        while(curr -> data != deleteData) {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next ;
        // 1-Node only
        if(curr == prev) {
            tail = NULL;
        }
        // >= 2 Nodes
        if(tail == curr) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &tail) {
    if(tail == NULL) {
        cout << "Nothing to print since it is empty\n" << endl;
    }
    Node* temp = tail;
    do{
        cout << temp -> data << " -> " ;
        temp = temp -> next;
    }while(temp != tail);
    cout << endl;
}

int main() {

    Node* tail = NULL;
    insertInCLL(tail, 20, 10);
    print(tail);

    /* insertInCLL(tail, 25, 20);
    print(tail);

    insertInCLL(tail, 30, 25);
    print(tail);

    insertInCLL(tail, 50, 25);
    print(tail);

    insertInCLL(tail, 22, 20);
    print(tail);

    insertInCLL(tail, 40, 30);
    print(tail);


    deleteInCLL(tail, 22);
    print(tail);

    deleteInCLL(tail, 30);
    print(tail);

    deleteInCLL(tail, 20);
    print(tail);

    deleteInCLL(tail, 40);
    print(tail); */

    deleteInCLL(tail, 20);
    print(tail);

    cout << "\nTail is at : " << tail -> data << endl;

    cout << endl;
    return 0;
}