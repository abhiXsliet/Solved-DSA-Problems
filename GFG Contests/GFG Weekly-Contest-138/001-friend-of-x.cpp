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
    string isFriend(int n, int x, int y, vector<int> &arr) {
        for (int i = 0; i < n; i++) {
            if (arr[i] + x == y) {
                return "yes";
            }
        }
        return "no";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int x;
        scanf("%d",&x);
        
        
        int y;
        scanf("%d",&y);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        string res = obj.isFriend(n, x, y, arr);
        
        cout<<res<<"\n";
        
    }
}

// } Driver Code Ends