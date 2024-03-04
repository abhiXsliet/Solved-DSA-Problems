// https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    // TC : O(N)
    // SC : O(N)
    int maxIndexDiff(int a[], int n) {   
        vector<int> min_left (n, a[0]);
        vector<int> max_right(n, a[n - 1]);
        
        for (int i = 1; i < n; i++) {
            min_left[i] = min(min_left[i - 1], a[i]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            max_right[i] = max(max_right[i + 1], a[i]);
        }
        
        int i = 0, j = 0;
        int maxDiff = 0;
        while (i < n && j < n) {
            if (min_left[i] <= max_right[j]) {
                maxDiff = max(maxDiff, j - i);
                j ++;
            }
            else i ++;
        }
        return maxDiff;
    }
};


//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends