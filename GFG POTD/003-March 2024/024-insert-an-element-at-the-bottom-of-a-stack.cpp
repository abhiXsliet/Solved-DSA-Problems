// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // TC : O(N)
    // SC : O(N)
    stack<int> insertAtBottom(stack<int> st, int x){
        stack<int> stk;
        while(!st.empty()) {
            int el = st.top();
            st.pop();
            stk.push(el);
        }
        // Insert the element at the bottom
        st.push(x);
        while(!stk.empty()) {
            int el = stk.top();
            stk.pop();
            st.push(el);
        }
        return st;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends