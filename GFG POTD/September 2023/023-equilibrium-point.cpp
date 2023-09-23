// https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1


//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    // TC = O(N), SC = O(1)
    int solve_way_1(long long a[], int n) {
        int i = 0, j = n - 1;
        long long sum1 = 0, sum2 = 0;
        
        while (i <= j) {

            if (sum1 == sum2) {
                sum1 += a[i++];
                sum2 += a[j--];
            }
            else if (sum1 < sum2) {
                sum1 += a[i++];
            }
            else {
                sum2 += a[j--];
            }
        }
        
        if (sum1 == sum2 && i-1 == j+1) {
            return i;
        }
        
        return -1;
    }
    
    // TC = O(N), SC = O(1)
    int solve_way_2(long long a[], int n) {
        long long sum = 0;
        for (int i = 0; i < n; i++) sum += a[i];
        
        long long pref = 0;
        for (int i = 0; i < n; i++) {
            sum -= a[i];
            
            if (sum == pref) return i + 1;
            
            pref += a[i];
        }
        
        return -1;
    }
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // return solve_way_1(a, n);
        
        return solve_way_2(a, n);
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends