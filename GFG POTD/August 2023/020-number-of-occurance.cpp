// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
private:
    int firstOcc(int arr[], int n, int x)
    {
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                high = mid - 1;
            }
            else if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

    int lastOcc(int arr[], int n, int x)
    {
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                low = mid + 1;
            }
            else if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return high;
    }

    int findOcc(int arr[], int n, int x, bool findFirst) {
        int low = 0;
	    int high = n - 1;
	    while(low <= high) {
	        int mid = low + (high - low)/2;
	        if(arr[mid] == x) {
	            if(findFirst) {
	                high = mid - 1;
	            }
	            else low = mid + 1;
	        }
	        else if(arr[mid] > x) {
	           high = mid - 1;
	        } else {
	            low = mid + 1;
	        }
	    }
	    return low;
    }

public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        // // Approach - 1 | TC = O(N)
        // int cnt = 0;
        // for(int i = 0; i < n; i++) {
        //     if(arr[i] == x)cnt++;
        // }
        // return cnt;


        // // Approach - 2 | TC = O(log(N))
        // int first = firstOcc(arr, n, x);
        // int last = lastOcc(arr, n, x);
        // return last - first + 1;


        // short code for Approach - 2
        int first = findOcc(arr, n, x, true);
        int last = findOcc(arr, n, x, false);
        return last - first;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends