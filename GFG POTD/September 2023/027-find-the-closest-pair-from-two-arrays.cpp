// https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  private:
    vector<int> solve_optimal(int arr[], int brr[], int n, int m, int x) {
        vector<int> result;
        int ele1 = 0, ele2 = 0;
        int diff = INT_MAX;
        
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            int sum = arr[i] + brr[j];
            int absDiff = abs(sum - x);
            
            if (absDiff < diff) {
                diff = absDiff;
                ele1 = arr[i];
                ele2 = brr[j];
            }
            else if (sum > x) j--;
            else i++;
        }
        
        result.push_back(ele1);
        result.push_back(ele2);
        return result;
    }
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        return solve_optimal(arr, brr, n, m, x);
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends