// https://www.geeksforgeeks.org/problems/find-length-of-loop/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}
// } Driver Code Ends
/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    bool isLoop(Node* &head, Node* &fast, Node* &slow) {
        while (slow != fast && fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow == fast;
    }
    
    int getNodesInCycle(Node* slow, Node* fast) {
        int cntNodes = 1;
        slow = slow -> next;
        while(slow != fast) {
            slow = slow -> next;
            cntNodes += 1;
        }
        return cntNodes;
    }
    
    // TC : O(N) 
    // SC : O(1)
    int approach_1(struct Node* head) {
        if (!head -> next) return 0;
        
        Node* slow = head;
        Node* fast = head -> next;
        
        bool loop = isLoop(head, fast, slow);
        if (!loop) return 0;
        
        slow = head;
        fast = fast -> next;
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return getNodesInCycle(slow, fast);
    }
    
    // TC : O(N) each node visited only twice
    // SC : O(1)
    int approach_2(struct Node* head) {
        if (!head -> next) return 0;
            
        Node* slow = head;
        Node* fast = head;
        
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if (slow == fast) {
                int loopLengthCnt = 1;
                Node* temp = slow;
                while (temp -> next != slow) {
                    temp = temp -> next;
                    loopLengthCnt += 1;
                }
                return loopLengthCnt;
            }
        }
        
        return 0;   // No loop detected
    }
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        // return approach_1(head);    // Brute : Loop? Yes? get the starting node of loop and cnt from there
        
        return approach_2(head);    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
    }
    return 0;
}
// } Driver Code Ends