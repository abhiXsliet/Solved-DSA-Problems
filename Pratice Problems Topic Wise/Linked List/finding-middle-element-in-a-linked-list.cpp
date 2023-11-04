// https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    private:
    // TC = O(N)
    int solve_approach_1(Node* head) {
        Node* temp = head;
        int cnt = 0;
        while(temp) {
            temp = temp -> next;
            cnt++;
        }
        
        int mid = cnt/2;
        temp = head;
        
        while(mid) {
            temp = temp -> next;
            mid--;
        }
        
        return temp -> data;
    }
    
    // TC = O(N)
    int solve_approach_2(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow -> data;
    }
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // return solve_approach_1(head);
        
        return solve_approach_2(head);
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends