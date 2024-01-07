// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1




//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  private:
    typedef long long ll;
    
    ll getPaintersCnt(int arr[], int n, int target) {
        int sum = 0;
        int cntPainters = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] + sum <= target) {
                sum += arr[i];
            }
            else {
                cntPainters ++;
                sum = arr[i];
            }
        }
        return cntPainters;
    }
  public:
    // TC : O(n log m) , m = sum of all boards' length
    // SC : O(1)
    ll minTime(int arr[], int n, int k)
    {
        int low  = 0;
        ll high = 0;
        for (int i = 0; i < n; i++) {
            low   = max(low, arr[i]);
            high += arr[i];
        }
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            if (getPaintersCnt(arr, n, mid) <= k) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends