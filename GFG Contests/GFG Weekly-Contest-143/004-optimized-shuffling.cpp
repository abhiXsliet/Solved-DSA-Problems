// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-143/problems



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,long long n,long long m)
    {
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,long long n)
    {
        for (long long i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (long long i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<long long> optShuffling(long long n, vector<vector<long long>> &edges) {
        // code here
    }
};


//{ Driver Code Starts.

int main(){
    long long t;
    scanf("%d ",&t);
    while(t--){
        
        long long n;
        scanf("%d",&n);
        
        
        vector<vector<long long>> edges(n-1, vector<long long>(2));
        Matrix::input(edges,n-1,2);
        
        Solution obj;
        vector<long long> res = obj.optShuffling(n, edges);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends