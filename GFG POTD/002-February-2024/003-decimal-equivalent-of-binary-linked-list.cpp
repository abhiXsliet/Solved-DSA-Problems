// https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1



//{ Driver Code Starts
// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

// } Driver Code Ends
/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
#include <bits/stdc++.h>
class Solution
{
    private:
    // TC : O(N)
    // SC : O(N)
    vector<int> precomputePowers(int n) {
        vector<int> powers(n);
        powers[0] = 1;
        for (int i = 1; i < n; i++) {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }
        return powers;
    }
    
    // TC : O(N)
    // SC : O(1)
    int pow(int base, int power) {
        int result = 1;
        for (int i = 0; i < power; i++) {
            result = (result * base) % MOD; 
        }
        return result;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    long long unsigned int solve_approach_1(Node* head) {
        int n = 0;
        Node* temp = head;
        while(temp) {
            temp = temp -> next;
            n++;
        }
        
        temp = head;
        int p = n - 1;
        int ans = 0;
        
        while (temp) {
            int val = temp -> data;
            ans = (ans + (val * pow(2, p))) % MOD;
            p--;
            temp = temp -> next;
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(100) ~= O(1)
    long long unsigned int solve_approach_2(Node* head) {
        int n = 0;
        Node* temp = head;
        while(temp) {
            temp = temp -> next;
            n++;
        }
        
        vector<int> powers = precomputePowers(n);
        
        temp = head;
        int p = n - 1;
        int ans = 0;
        
        while (temp) {
            int val = temp -> data;
            ans = (ans + (val * powers[p]) ) % MOD;
            p--;
            temp = temp -> next;
        }
        return ans;
    }
    public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list 
    long long unsigned int decimalValue(Node *head)
    {
        // return solve_approach_1(head);
        
        return solve_approach_2(head);
    }
};


//{ Driver Code Starts.

void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isEmpty(struct Node *head);

/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        Solution obj;
        cout << obj.decimalValue(head) << endl;
    }
    return 0;
}
// } Driver Code Ends