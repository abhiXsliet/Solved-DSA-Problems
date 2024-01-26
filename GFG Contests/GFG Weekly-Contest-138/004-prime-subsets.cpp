// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-138/problems



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int primeSubsets(int N, vector<int> &Arr) {
        // code here
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> Arr(N);
        Array::input(Arr,N);
        
        Solution obj;
        int res = obj.primeSubsets(N, Arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends