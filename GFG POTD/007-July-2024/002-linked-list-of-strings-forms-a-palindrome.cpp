// https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};

Node *newNode(string str) {
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

void print(Node *root) {
    Node *temp = root;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
// } Driver Code Ends
/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    void getString(Node* head, string& store) {
        while(head) {
            store += (head -> data);
            head   = head -> next;
        }
    }

    // TC : O(N)
    // SC : O(1)
    bool isPalindrome(string& store) {
        int i = 0, j = store.length() - 1;
        while (i <= j) {
            if (store[i] != store[j]) {
                return false;
            }
            i ++, j --;
        }
        return true;
    }
  public:
    // TC : O(N)
    // SC : O(N)
    bool compute(Node* head) {
        string store;
        getString(head, store);
        
        return isPalindrome(store);
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++) {
            string str = "";
            cin >> str;
            if (head == NULL)
                head = temp = new Node(str);
            else {
                temp->next = new Node(str);
                temp = temp->next;
            }
        }
        Solution ob;
        bool ans = ob.compute(head);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends