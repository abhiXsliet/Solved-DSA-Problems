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
  private:
    typedef long long ll;
    ll solve_brute(int n, int k, vector<int>& arr) {
        ll ans = INT_MIN;
        for (ll i = 1; i <= k; i++) {
            ll sum = 0;
            for (ll j = 0; j < i; j++) {
                sum += arr[j];
            }
            ans = max(ans, sum);
            
            for (ll j = i; j < n; j++) {
                sum += arr[j] - arr[j - i];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
  public:
    long long kMaxSubarray(int n, int k, vector<int> &arr) {
        return solve_brute(n, k, arr);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        long long res = obj.kMaxSubarray(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends