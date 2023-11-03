// https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
private:
    // TC = O(N * N * N) -> TLE
    bool solve_brute_1(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long sum = pow(arr[i], 2) + pow(arr[j], 2);
                
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j && sum == pow(arr[k], 2)) {
                        return true;
                        break;
                    }
                }
            }
        }
        return false;
    }
    
    // TC = O(N * N * N ) -> TLE
    bool solve_brute_2(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    int a = arr[i] * arr[i];
                    int b = arr[j] * arr[j];
                    int c = arr[k] * arr[k];
                    
                    if (a == b + c || b == a + c || c == a + b) 
                        return true;
                }
            }
        }
        return false;
    }
    
    // TC = O(N * N) -> TLE
    // SC = O(1)
    bool solve_better_1(int arr[], int n) {
        
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * arr[i];
        }
        
        // O(N * log(N)) 
        sort(arr, arr+n);
        
        for (int i = n - 1; i > 1; i--) {
    
            int j = 0; 
            int k = i - 1;
            
            while (j < k) {
                int c = arr[i], a = arr[j], b = arr[k];
                
                if (a + b == c) return true;
                
                if (a + b < c) j++;
                else k--;
            }
        }
        
        return false;
    }
    
    // TC = O(N * N)
    // SC = O(N)
    bool solve_better_2(int arr[], int n) {
        unordered_map<int, int> mpp;
        
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * arr[i];
            mpp[arr[i]]++;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = arr[i] + arr[j];
                if (mpp.find(target) != mpp.end()) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // TC = O(N + max(arr[i]) ^ 2)
    // SC = O(max(arr[i]))
    bool solve_optimal(int arr[], int n) {
        int maxi = *max_element(arr, arr+n);

        maxi = maxi * maxi;

        vector<int> storeFreq(maxi + 1, 0);
        
        // store the freq of squares of each element
        for (int i = 0; i < n; i++) {
            storeFreq[arr[i]*arr[i]]++;
        }
        
        // for all possible 'a'
        for (int i = 1; i <= maxi; i++) {
            if (storeFreq[i] == 0) continue;
            
            // for all possible 'b'
            for (int j = 1; j < maxi; j++) {
                if (storeFreq[j] == 0 || (i == j && storeFreq[i] == 1))
                    continue;
                    
                int c = (i + j); // since indexs are the squares of the elements
                
                if (c > maxi) continue; // out of bound
                
                if (storeFreq[c] > 0)
                    return true;
            }
        }
        return false;
    }
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	   // return solve_brute_1(arr, n);
	   
	   //return solve_brute_2(arr, n);
	   
	   //return solve_better_1(arr, n);
	   
	   //return solve_better_2(arr, n);
	   
	   return solve_optimal(arr, n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends