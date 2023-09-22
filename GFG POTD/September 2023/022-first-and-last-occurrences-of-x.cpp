// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int first_occ(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (x == arr[mid]) {
                result = mid;
                high = mid - 1;
            }
            else if (x < arr[mid])
                high = mid - 1;
            else low = mid + 1;
        }
        return result;
    }
    
    int last_occ(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (x == arr[mid]) {
                result = mid;
                low = mid + 1;
            }
            else if (x < arr[mid])
                high = mid - 1;
            else low = mid + 1;
        }
        return result;
    }
    
    int find_occ(int arr[], int n, int x, bool flag) {
        int low = 0, high = n - 1;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (x == arr[mid]) {
                res = mid;
                if (flag == 0) high = mid - 1;
                else low = mid + 1;
            }
            else if (x < arr[mid]) 
                high = mid - 1;
                
            else low = mid + 1;
        }
        return res;
    }
    
    // TC = O(N)
    // SC = O(1)
    vector<int> solve_longer_code(int arr[], int n, int x) {
        int first = first_occ(arr, n, x);
        
        int last = last_occ(arr, n, x);
        
        vector<int> result(2, 0);
        result[0] = first;
        result[1] = last;
        
        return result;
    }
    
    // TC = O(N)
    // SC = O(1)
    vector<int> solve_shorter_code(int arr[], int n, int x) {
        int first = find_occ(arr, n, x, 0);
        int last  = find_occ(arr, n, x, 1);
        
        vector<int> result(2, 0);
        
        result[0] = first;
        result[1] = last;
        
        return result;
    }
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // return solve_longer_code(arr, n, x);
        
        return solve_shorter_code(arr, n, x);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends