// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    private:
    void swapIfGreater(long long arr1[], long long arr2[], int idx1, int idx2) {
        if(arr1[idx1] > arr2[idx2]) {
            swap(arr1[idx1], arr2[idx2]);
        }
    }
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        {   
            /* 
            //TC = O((n+m) * log(n+m))
            //SC = O(1)
            int left = n-1;
            int right = 0;
            while(left >= 0 && right < m) {
                if(arr1[left] > arr2[right]) swap(arr1[left--], arr2[right++]);
                else break;
            } 
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
             */



            //TC = O((n+m) * log(n+m))
            //SC = O(1)
            int len = ( n + m );
            int gap = (len) / 2 + (len) % 2;
            while(gap > 0) {
                int left = 0;
                int right = left + gap;
                while(right < len) {
                    // comparing arr1 and arr2 elements
                    if(left < n && right >= n) {
                        swapIfGreater(arr1, arr2, left, right-n);
                    }
                    // comparing arr2 and arr2 elements
                    else if(left >= n) {
                        swapIfGreater(arr2, arr2, left-n, right-n);
                    }
                    // comparing arr1 and arr1 elements
                    else {
                        swapIfGreater(arr1, arr1, left, right);
                    }
                    left++, right++;
                }
                if(gap == 1)break;
                gap = (gap / 2) + (gap % 2);
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends