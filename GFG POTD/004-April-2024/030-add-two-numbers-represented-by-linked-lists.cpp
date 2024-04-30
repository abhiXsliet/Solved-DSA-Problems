// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1



//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
    struct Node* reverse1(struct Node *head) {
       Node *temp = NULL;
        while(head != NULL) {
            Node *temp1 = head->next;
            head->next  = temp;
            temp = head;
            head = temp1;
        }
        return temp;
    }
public:
    struct Node* addTwoLists(struct Node* n1, struct Node* n2) {
        Node *num1 = reverse1(n1);
        Node *num2 = reverse1(n2);
        int carry  = 0;
        vector<int>v;
        while(num1 != NULL || num2 != NULL || carry != 0) {
            int x = carry;
            if(num1 != NULL) {
               x += num1->data;
               num1 = num1->next;
            }
            if(num2 != NULL) {
               x += num2->data;
               num2 = num2->next;
            }
            carry = x / 10;
            x = x % 10;
            v.push_back(x);
        }
        
        int i = v.size() - 1;
        while (i >= 0 && v[i] == 0) {
            i--;
        }

        bool isZero = true;
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] != 0) {
                isZero = false;
                break;
            }
        }

        if (isZero) {
            cout << "0";
        } else {
            while (i >= 0) {
                cout << v[i] << " ";
                i--;
            }
        }
        
        return NULL;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends