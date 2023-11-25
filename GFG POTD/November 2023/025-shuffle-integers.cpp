// https://www.geeksforgeeks.org/problems/shuffle-integers2401/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:
	// TC = O(N)
	// SC = O(N) -> Recursive depth
	void solve_1(int arr[], int i, int j, int n) {
	    if (n <= 0) return;
	    
	    int a = arr[i];
	    int b = arr[j];
	    
	    solve_1(arr, i-1, j-1, n-2);
	    
	    arr[n - 2] = a;
	    arr[n - 1] = b;
	}
	
	// TC = O(N)
	// SC = O(1)
	void solve_approach_1(int arr[], int n) {
	    int i = n/2 - 1;
	    int j = n - 1;
	    solve_1(arr, i, j, n);
	}
	
	// TC = O(N)
	// SC = O(1)
	void solve_approach_2(int arr[], int n) {
	    int maxVal = 1e4;
	    
	    for (int i = 2, j = 1; i < n; i += 2, j++) {
	        arr[i] = (arr[j] % maxVal) * maxVal + arr[i];
	    }
	    
	    for (int i = 1, j = n/2; i < n; i += 2, j++) {
	        arr[i] = (arr[j] % maxVal) * maxVal + arr[i];
	    }
	    
	    for (int i = 1; i < n; i++) {
	        arr[i] = arr[i] / maxVal;
	    }
	}
	
	// TC = O(N)
	// SC = O(1)
	void solve_approach_3(int arr[], int n) {
	    int k = n/2 - 1;
	    
	    for (int i = n - 1; i >= n / 2; i--) {
	        arr[i] << 10;
	        arr[i] |= arr[k];
	        k--;
	    }
	    
	    k = 0;
	    
	    for (int i = n / 2; i < n; i++) {
	        arr[k++] = arr[i] & 1023;
	        arr[k++] = arr[i] >> 10;
	    }
	}
	public:
	void shuffleArray(int arr[],int n)
	{
	   // solve_approach_1(arr, n);
	   
	   //solve_approach_2(arr, n);
	   
	   solve_approach_2(arr, n);
	}
};

//{ Driver Code Starts.


int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends