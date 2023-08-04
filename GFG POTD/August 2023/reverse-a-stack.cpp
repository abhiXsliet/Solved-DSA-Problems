// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// TC = O(N^2)
// SC = O(N)
class Solution{
    void insert(stack<int> &St, int topEle) {
        if(St.empty()) {
            St.push(topEle);
            return ;
        }
        int newTop = St.top();
        St.pop();
        insert(St, topEle);
        St.push(newTop);
    }
public:
    void Reverse(stack<int> &St){
        if(St.empty()) return ;
        
        int topEle = St.top();
        St.pop();
        Reverse(St);
        insert(St, topEle);
    }
};

// Another Better Solution
// TC = O(N)
// SC = O(N)
class Solution{
    void solve(queue<int> &q, stack<int>& St) {
        if(St.empty()) return;
        
        q.push(St.top());
        St.pop();
        solve(q, St);
        St.push(q.front());
        q.pop();
    }
public:
    void Reverse(stack<int> &St){
        queue<int>q;
        solve(q, St);
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