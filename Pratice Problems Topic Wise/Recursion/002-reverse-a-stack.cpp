// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1



//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    // TC : O(N)
    // SC : O(N) -> Auxiliary Space Used by queue
    void brute_1(stack<int>& stk, queue<int>& q) {
        if (stk.empty()) return;
        
        q.push(stk.top());
        stk.pop();
        
        brute_1(stk, q);
        
        stk.push(q.front());
        q.pop();
    }
    
    // TC : O(N)
    // SC : O(N) -> Auxiliary Space Used by newStack
    void brute_2(stack<int>& stk, stack<int>& newStk) {
        if (stk.empty()) return;
        
        int val = stk.top();
        stk.pop();
        newStk.push(val);

        brute_2(stk, newStk);
    }
    
    // TC : O(N)
    // SC : O(N) -> Space Used By Recursive Stack
    void insertAtBottom(stack<int>& stk, int ele) {
        // if the stack becomes push the element
        if (stk.empty()) {
            stk.push(ele);
            return;
        }
        
        // if the stack is not empty then pop all the elements first
        int val = stk.top(); 
        stk.pop();
        
        insertAtBottom(stk, ele);
        stk.push(val);
    }
    
    // TC : O(N^2)
    // SC : O(N) -> Space Used By Recursive Stack
    void optimal(stack<int>& stk) {
        if (stk.empty()) return;
        
        int ele = stk.top();
        stk.pop();

        optimal(stk);
        
        insertAtBottom(stk, ele);
    }
public:
    void Reverse(stack<int> &stk){
        // queue<int> q;
        // brute_1(stk, q);         // Auxiliary Space => O(N) : Queue
        
        // stack<int> newStk;
        // brute_2(stk, newStk);    // Auxiliary Space => O(N) : Stack
        // stk = newStk;
        
        return optimal(stk);        // Auxiliary Space => O(1)
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends