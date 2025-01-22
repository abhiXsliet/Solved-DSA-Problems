// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1



//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
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
  private:
    // TC : O(N)
    // SC : O(N) Stack Space used by recursive Depth
    Node* reverse(Node* head) {
        if (!head || !head -> next) 
            return head;
            
        Node* nextHead = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        
        return nextHead;
    }
    
    // TC : O(N)
    // SC : O(1)
    Node* approach_1(Node* num1, Node* num2) {
        Node* rNum1 = reverse(num1);
        Node* rNum2 = reverse(num2);

        Node* temp1 = rNum1;
        Node* temp2 = rNum2;
        int carry   = 0;
        Node* res   = new Node(-1);
        Node* temp  = res;
        
        while (temp1 || temp2 || carry) {
            int sum = 0;
            if (temp1) {
                sum  += temp1 -> data;
                temp1 = temp1 -> next;
            }
            if (temp2) {
                sum  += temp2 -> data;
                temp2 = temp2 -> next;
            }
            
            sum    += carry;
            int val = sum % 10;
            carry   = sum / 10;
            temp -> next = new Node(val);
            temp = temp -> next;
        }
        
        res = res -> next;  // to skip dummy node
        Node* rResult = reverse(res);

        // skip leading zeros
        temp = rResult;
        while (temp) {
            if (temp -> data == 0) {
                temp = temp -> next;
                rResult = temp;
            } else break;
        }
        return rResult;
    }
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        return approach_1(num1, num2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends