// https://practice.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1


//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    private:
    long long solve_brute(int arr[], int n) {
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        
        return sum;
    }
    
    // TC = O(N)
    long long solve_optimal(int arr[], int n) {
        long sum = 0;
        
        for (int i = 0; i < 32; i++) {
            long cntZero = 0;
            long cntOne  = 0;
            
            for (int j = 0; j < n; j++) {
                
                if (arr[j] % 2 == 0) {
                    cntZero++;
                }
                else cntOne++;
                
                arr[j] /= 2;
            }
            
            sum += (cntOne * cntZero) * (1 << i);
        }
        return sum;
    }
    
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    // 	return solve_brute(arr, n);
    
        return solve_optimal(arr, n);
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends