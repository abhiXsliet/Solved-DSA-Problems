// https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1



//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    vector<int> solve_brute(int arr[], int n) {
        int size = n + 2;
        vector<int> result;
        unordered_map<int, int> count;
        for (int i = 0; i < size; i++) {
            if (count[arr[i]] == 1) {
                result.push_back(arr[i]);
            }
            count[arr[i]]++;
        }
        return result;
    }
    // TC : O(N)
    // SC : O(1)
    vector<int> solve_optimal(int arr[], int n) {
        int size = n + 2;
        vector<int> result;
        for (int i = 0; i < size; i++) {
            int idx = abs(arr[i]);
            if (arr[idx] > 0) {
                arr[idx] = -arr[idx];
            }
            else result.push_back(idx);
        }
        return result;
    }
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // return solve_brute(arr, n);
        
        return solve_optimal(arr, n);
    }
};


//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends