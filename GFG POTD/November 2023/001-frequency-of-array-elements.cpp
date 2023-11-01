// https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
    private:
    
    // TC = O(N)
    // SC = O(N)
    void solve_brute(vector<int>& arr, int N, int P) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < N; i++) 
            mpp[arr[i]]++;
            
        for (int i = 0; i < N; i++) 
            arr[i] = mpp[i+1];
    }
    
    // TC = O(N)
    // SC = O(1)
    void solve_optimal(vector<int>& arr, int N, int P) {
        int mod = P + 1;
        
        for (int i = 0; i < N; i++) {
            if ((arr[i] % mod) <= N) {
                arr[arr[i] % mod - 1] += mod;
            }
        }
        
        for (int i = 0; i < N; i++) {
            arr[i] /= mod;
        }
    }
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // solve_brute(arr, N, P);
        
        solve_optimal(arr, N, P);
    }
};


//{ Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}

// } Driver Code Ends