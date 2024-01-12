// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    private:
    // TC : O(N)
    // SC : O(K) + O(N - K)
    queue<int> solve_approach_1(queue<int> q, int k) {
        stack<int> stk;
        while(k--) {
            stk.push(q.front());
            q.pop();
        }
        
        vector<int> left;
        while(!q.empty()) {
            left.push_back(q.front());
            q.pop();
        }
        
        while(!stk.empty()) {
            q.push(stk.top());
            stk.pop();
        }
        
        for(int i = 0; i < left.size(); i++) {
            q.push(left[i]);
        }
        return q;
    }
    
    // TC : O(N)
    // SC : O(N)
    queue<int> solve_approach_2(queue<int> q, int k) {
        stack<int> stk;
        // Push first k elements into the stack
        int K = k;
        while(K--) {
            stk.push(q.front());
            q.pop();
        }
          
        while(!stk.empty()) {
            q.push(stk.top());
            stk.pop();
        }
        
        // pop rest (n - k) elements from the queue
        int size = q.size() - k;
        while (size--) {
            
            int el = q.front();
            q.pop();
            q.push(el);
        }
        
        return q;
    }
    public:
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // return solve_approach_1(q, k);
        
        return solve_approach_2(q, k);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends