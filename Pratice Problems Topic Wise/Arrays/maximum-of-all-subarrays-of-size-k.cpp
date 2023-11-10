// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  private:
    // TC = O(N * N) -> TLE
    // SC = O(1)
    vector<int> solve_brute(int *arr, int n, int k) {
        vector<int> result;
        for (int i = 0; i <= n - k; i++) {
            int sum = INT_MIN;
            for (int j = i; j < k + i; j++) {
                sum = max(sum, arr[j]);
            }
            result.push_back(sum);
        }
        return result;
    }
    
    // TC = O(N * K)
    // SC = O(1)
    // SLIDING WINDOW APPROACH (using two pointer)
    vector<int> solve_better_1(int *arr, int n, int k) {
        vector<int> result;
        
        int left = 0;
        int maximum = INT_MIN;
        
        for (int right = 0; right < n; right++) {
            maximum = max(maximum, arr[right]);
            
            if (right - left + 1 == k) {
                result.push_back(maximum);
                
                if (arr[left] == maximum) {
                    int maxi = INT_MIN;
                    for (int i = left + 1; i <= right; i++) {
                        maxi = max(maxi, arr[i]);
                    }
                    maximum = maxi;
                    
                }
                
                left++;
            }
        }
        
        return result;
    }
    
    // TC = O(N * log(K))
    // SC = O(K)
    // SLIDING WINDOW APPROACH (insert at max k elements in maxheap)
    vector<int> solve_better_2(int *arr, int n, int k) {
        priority_queue<pair<int, int>> pq;   // maxheap {arr[i], i}
        vector<int> result;
        //push first k-elements to maxheap
        for (int i = 0; i < k; i++)
            pq.push({arr[i], i});
            
        result.push_back(pq.top().first);
        
        //process the remaining elements
        for (int i = k; i < n; i++) {
            pq.push({arr[i], i});
            
            // pop elements more than window size from maxheap
            while(i - pq.top().second >= k) {
                pq.pop();
            }
            
            result.push_back(pq.top().first);
        }
        return result;
    }
    
    // TC = O(N)
    // SC = O(K)
    vector<int> solve_optimal(int *arr, int n, int k) {
        vector<int> result;
        deque<int> dq;
        
        for (int i = 0; i < n; i++) {
            
            // Remove elements that are smaller than 
            // the current element from the back
            while(dq.size() && arr[dq.back()] <= arr[i]) 
                dq.pop_back();
           
            // Add the current element's index to the deque
            dq.push_back(i);
            
            // Remove elements outside the current window
            while(dq.front() <= i - k)
                dq.pop_front();
            
            // Add the max ele of the curr window to result
            if (i + 1 >= k) 
                result.push_back(arr[dq.front()]);
        }
        
        return result;
    }
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // return solve_brute(arr, n, k);
        
        // return solve_better_1(arr, n, k);
        
        // return solve_better_2(arr, n, k);
        
        return solve_optimal(arr, n, k);
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends