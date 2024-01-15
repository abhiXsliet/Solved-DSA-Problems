// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-137/problems


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
    int candyShop(int n, vector<int> &candies) {
        unordered_map<int, int> mpp;
        for (int price : candies) {
            mpp[price] ++;
        }
        
        int minAmount = 0;
        for (auto& it : mpp) {
            minAmount += it.first;
        }
        return minAmount;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> candies(n);
        Array::input(candies,n);
        
        Solution obj;
        int res = obj.candyShop(n, candies);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends