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
    int minimizeArrayScore(int n, vector<int> &arr) {
        sort(begin(arr), end(arr));
        
        int i = 0, j = n - 1;
        
        int len = n / 2;
        
        vector<int> arrCopy;
        
        while (len) {
            int sum = arr[i] + arr[j];
            arrCopy.push_back(sum);
            i++, j--;
            len--;
        }
        
        return *max_element(begin(arrCopy), end(arrCopy));
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
        int res = obj.minimizeArrayScore(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends