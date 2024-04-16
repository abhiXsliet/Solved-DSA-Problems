// https://www.geeksforgeeks.org/problems/minimize-the-difference/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  private:
    // TC : O(N*K)
    // SC : O(1)
    int solve_brute(int n, int k, vector<int>& arr) {
        int result = INT_MAX;
        for (int i = 0; i <= n-k; i++) {
            int minVal = INT_MAX;
            int maxVal = INT_MIN;
            for (int j = 0; j < n; j++) {
                if (j < i || j >= i + k) { // considering elements outside the subarray
                    minVal = min(minVal, arr[j]);
                    maxVal = max(maxVal, arr[j]);
                }
            }
            result = min(result, maxVal - minVal);
        }
        return result;
    }
    
    // TC : O(N*N)
    // SC : O(N)
    int solve_brute_2(int n, int k, vector<int>& arr) {
        int result = INT_MAX;
        
        unordered_map<int, int>mpp;
        unordered_set<int> st;
        for (int& num : arr) {
            mpp[num] ++;
            st.insert(num);
        }
        
        int i = 0, j = 0;
        while(i + k <= n) {
            
            while(j < i + k) {
               mpp[arr[j]] --;
                if (mpp[arr[j]] == 0) {
                    st.erase(arr[j]);
                } 
                j ++;
            }

            int maxi = INT_MIN;
            int mini = INT_MAX;
            for (auto& it : st) {
                maxi = max(maxi, it);
                mini = min(mini, it);
            }
            
            result = min(result, maxi - mini);
            
            st.insert(arr[i]);
            mpp[arr[i]] ++;
            
            i ++;
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_optimal(int n, int k, vector<int>& arr) {
        vector<int>post_max(n, arr[n-1]);
        vector<int>post_min(n, arr[n-1]);
        
        for(int i = n - 2; i >= 0; i--){
            post_max[i] = max(arr[i], post_max[i + 1]);
            post_min[i] = min(arr[i], post_min[i + 1]);
        }
        
        int ans = post_max[k] - post_min[k];
        int maxi = arr[0], mini = arr[0];
        
        for(int i = 1; i < n - k; i++){
            ans = min(ans, max(post_max[i + k], maxi) - min(post_min[i + k], mini));

            maxi = max(arr[i], maxi);
            mini = min(arr[i], mini);
        }
        
        ans = min(ans, maxi - mini);
        return ans;
    }
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // return solve_brute(n, k, arr);
        
        // return solve_brute_2(n, k, arr);
        
        return solve_optimal(n, k, arr);
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}
// } Driver Code Ends