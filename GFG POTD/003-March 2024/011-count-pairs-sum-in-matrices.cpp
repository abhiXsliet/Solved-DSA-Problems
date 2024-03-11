// https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1



//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//User function template for C++
class Solution{
private:
    // TC : O(N*N) Where N = mat1.size() & mat2.size()
    // SC : O(N)
    int solve_brute(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int n, int x) {
        unordered_set<int> st;
	    for (auto& mat : mat2) {
	        for (auto& num : mat) {
	            st.insert(num);
	        }
	    }
	    
	    int ans = 0;
	    for (auto& mat : mat1) {
	        for (int& num : mat) {
	            if (st.find(x - num) != st.end()) 
	                ans ++;
	        }
	    }
	    return ans;
    }
    
    // TC : O(N*N*N) Where N = mat1.size() & mat2.size()
    // SC : O(1)
    int solve_better_1(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int n, int x) {
        int ans = 0;
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            int tar = x - mat1[i][j];
	            int r;
    	        for (r = 0; r < n; r++) {
    	            if (mat2[r][0] <= tar) continue;
    	            else break;
    	        }
    	        for (int c = 0; c < n; c++) {
    	            if (r - 1 >= 0 && mat2[r-1][c] == tar) {
    	                ans ++;
    	            }
    	        }
	        }
	    }
	    return ans;
    }
    
    // TC : O(log(N))
    // SC : O(1)
    int binarySearch(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == target) return 1;
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
    
    // TC : O(N*N*N) Where N = mat1.size() & mat2.size()
    // SC : O(1)
    int solve_better_2(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int n, int x) {
        int ans = 0;
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            int tar = x - mat1[i][j];
	            int r;
    	        for (r = 0; r < n; r++) {
    	            if (mat2[r][0] <= tar) continue;
    	            else break;
    	        }
    	        
    	        if (r-1 >= 0 && binarySearch(mat2[r-1], tar)) 
    	            ans ++;
	        }
	    }
	    return ans;
    }
    
    // TC : O(N*N) Where N = mat1.size() & mat2.size()
    // SC : O(1)
    int solve_optimal(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int n, int x) {
        int r1 = 0, c1 = 0;          // top left
        int r2 = n - 1, c2 = n - 1;  // bottom right
        
        int ans = 0;
        while (r1 < n && r2 >= 0) {
            int sum = mat1[r1][c1] + mat2[r2][c2];
            if (sum == x) {
                ans ++;
                c1 ++, c2 --;
            }
            else if (sum < x) c1 ++;
            else c2 --;
            
            if (c1 == n) {
                r1 ++, c1 = 0;
            }
            
            if (c2 < 0) {
                r2 --, c2 = n - 1;
            }
        }
        return ans;
    }
public:	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x) {
	   // return solve_brute(mat1, mat2, n, x);
	   
	   //return solve_better_1(mat1, mat2, n, x);
	   
	   //return solve_better_2(mat1, mat2, n, x);
	   
	   return solve_optimal(mat1, mat2, n, x);  // Two Pointer Technique
	}
};


//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends