// https://practice.geeksforgeeks.org/problems/queue-reversal/1


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {   
        queue<int>ans;
        stack<int>st;
        while(!q.empty()) {
            int ele = q.front();
            q.pop();
            st.push(ele);
        }
        
        while(!st.empty()) {
            int ele = st.top();
            st.pop();
            ans.push(ele);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends