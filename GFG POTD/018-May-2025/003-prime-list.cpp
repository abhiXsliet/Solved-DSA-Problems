// https://www.geeksforgeeks.org/problems/prime-list--170646/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}
// } Driver Code Ends

// User function Template for C++
/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  private:
    vector<int> getPrimes() {
        int n = 1e5;
        vector<bool> primes(n, 1);
        primes[0] = primes[1] = 0;
        for (int i = 0; i*i < n; i ++) {
            if (primes[i]) {
                for (int j = 2*i; j < n; j += i) {
                    primes[j] = 0;
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i ++) {
            if (primes[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
  public:
    // TC : O(N * log(primes.size())) [primes.size() at max 9592]
    // SC : O(primes.size())
    Node *primeList(Node *head) {
        vector<int> primes = getPrimes();
        Node* temp = head;
        while (temp) {
            int value = temp -> val;
            int idx = lower_bound(begin(primes), end(primes), value) - begin(primes);

            int d1  = (idx > 0) ? abs(primes[idx - 1] - value) : INT_MAX;
            int d2  = abs(primes[idx] - value);
            
            temp -> val = (d1 <= d2) ? primes[idx - 1] : primes[idx];
            temp = temp -> next;
        }
        return head;
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

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends