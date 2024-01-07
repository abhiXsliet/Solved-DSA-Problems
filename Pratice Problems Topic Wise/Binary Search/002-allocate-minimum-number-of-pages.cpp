// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1



//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private:
    int getStudentsCnt(int arr[], int n, int targetPageCnt) {
        int pageSum     = 0;
        int studentsCnt = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] + pageSum <= targetPageCnt) {
                pageSum += arr[i];
            }
            else {
                studentsCnt ++;
                pageSum = arr[i];
            }
        }
        return studentsCnt;
    }
    public:
    //Function to find minimum number of pages.
    // TC : O(sum * log(N)) where N = array size and sum = total no. of pages
    // SC : O(1)
    int findPages(int A[], int N, int M) 
    {
        if (M > N) return -1;
        
        int low  = 0;
        int high = 0;
        for (int i = 0; i < N; i++) {
            low   = max(low, A[i]);
            high += A[i];
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (getStudentsCnt(A, N, mid) <= M) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends