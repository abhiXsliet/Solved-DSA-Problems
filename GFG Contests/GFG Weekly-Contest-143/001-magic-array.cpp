// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-143/problems



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
    bool isMagicArray(int n, vector<int> &arr) {
        bool isEven = 0;
        bool isOdd  = 0;
        
        if (arr[0] % 2 == 0) isEven = 1;
        else isOdd = 1;
        
        for (int i = 1; i < n; i += 2) {
            if (isEven) {
                if (arr[i] % 2) continue;
                else return 0;
            }
            
            if (isOdd) {
                if (arr[i] % 2 == 0) continue;
                else return 0;
            }
        }
        
        for (int i = 2; i < n; i += 2) {
            if (isEven) {
                if (arr[i] % 2 == 0) continue;
                else return 0;
            }
            
            if (isOdd) {
                if (arr[i] % 2) continue;
                else return 0;
            }
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        bool res = obj.isMagicArray(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends