// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1



//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int index = sizeOfStack/2;
        vector<int> store;
        while(!s.empty()) {
            int ele = s.top();
            s.pop();
            store.push_back(ele);
        }
        
        vector<int>::iterator it;
        it = store.begin()+index;
        store.erase(it);
        
        for(auto& i : store)
            cout << i << " ";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends