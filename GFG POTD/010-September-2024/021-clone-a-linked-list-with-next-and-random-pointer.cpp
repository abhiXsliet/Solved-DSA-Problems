// https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1




//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->random == NULL)
            k = -1;
        else
            k = temp->random->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*tail_ref)->next = new_node;
    }
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {
    Node *temp1 = head;
    Node *temp2 = res;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data)
            return false;
        if ((temp1->random == NULL && temp2->random != NULL) ||
            (temp1->random != NULL && temp2->random == NULL) ||
            (temp1->random != NULL && temp2->random != NULL &&
             temp1->random->data != temp2->random->data))
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

// } Driver Code Ends
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    Node* approach_1(Node* head) {
        unordered_map<Node*, Node*> mpp;
        
        Node* newH = new Node(-1);
        Node* temp = head;
        Node* curr = newH;
        
        while(temp) {
            Node* add = new Node(temp -> data);
            curr -> next = add;
            
            mpp[temp] = add; // Catch : Track new Node corresponding to original node
            
            temp = temp -> next;
            curr = curr -> next;
        }
        
        temp = head;
        curr = newH -> next; // skip dummy node
        
        while (temp) {
            if (mpp[temp -> random]) {
                curr -> random = mpp[temp -> random];
            } else {
                curr -> random = NULL;
            }
            curr = curr -> next;
            temp = temp -> next;
        }
        
        // delete dummy
        temp = newH;
        newH = newH -> next;
        delete temp;
        
        return newH;
    }
    
    // TC : O(N)
    // SC : O(1)
    Node* approach_2(Node* head) {
        Node* temp = head;
        while(temp) {
            Node* add  = new Node(temp -> data);
            Node* forw = temp -> next;
            temp -> next = add;
            add -> next  = forw;
            temp = temp -> next -> next;
        }
        
        temp = head;
        while (temp) {
            if (temp -> random) {
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }
        
        // separate the LL 
        temp = head;
        Node* curr = head -> next;
        Node* newH = curr;
        
        while (temp) {
            temp -> next = curr -> next;
            temp = temp -> next;
            
            if (temp) curr -> next = temp -> next;
            curr = curr -> next;
        }
        
        return newH;
    }
  public:
    Node *copyList(Node *head) {
        // return approach_1(head);
        
        return approach_2(head);
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore the newline after T
    while (T--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = NULL, *tail = NULL;
        for (int i = 0; i < arr.size(); ++i) {
            append(&head, &tail, arr[i]);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> arr2;
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Node *temp = head;
        for (int i = 0; i < arr2.size(); i += 2) {
            int a = arr2[i];
            int b = arr2[i + 1];

            Node *tempA = head;
            Node *tempB = head;
            for (int j = 1; j < a; ++j) {
                tempA = tempA->next;
            }
            for (int j = 1; j < b; ++j) {
                tempB = tempB->next;
            }

            tempA->random = tempB;
        }

        Solution ob;
        Node *res = ob.copyList(head);
        if (res == head) {
            cout << "false" << endl;
            continue;
        }
        if (validation(head, res)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}
// } Driver Code Ends