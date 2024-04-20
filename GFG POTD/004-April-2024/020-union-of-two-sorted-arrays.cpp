// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    private:
    // TC : O(N+M * log(N+M))
    // SC : O(N+M)
    vector<int> approach_1(int arr1[], int arr2[], int n, int m) {
        vector<int> result;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            if (st.find(arr1[i]) == st.end())
                result.push_back(arr1[i]);
            st.insert(arr1[i]);
        }
        for (int i = 0; i < m; i++) {
            if (st.find(arr2[i]) == st.end()) 
                result.push_back(arr2[i]);
            st.insert(arr2[i]);
        }
        sort(begin(result), end(result));
        return result;
    }
    
    // TC : O(N+M)
    // SC : O(1)
    vector<int> approach_2(int arr1[], int arr2[], int n, int m) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (i > 0 && arr1[i] == arr1[i - 1]) {
                i ++;
                continue;
            }
            if (j > 0 && arr2[j] == arr2[j - 1]) {
                j ++;
                continue;
            }
            
            if (arr1[i] < arr2[j]) {
                result.push_back(arr1[i]);
                i ++;
            }
            else if (arr1[i] > arr2[j]) {
                result.push_back(arr2[j]);
                j ++;
            }
            else {
                result.push_back(arr1[i]);
                i ++, j ++;
            }
        }
        while (i < n) {
            if (i > 0 && arr1[i] != arr1[i - 1]) {
                result.push_back(arr1[i]);
            }
            i ++;
        }
        while (j < m) {
            if (j > 0 && arr2[j] != arr2[j - 1]) {
                result.push_back(arr2[j]);
            }
            j ++;
        }
        return result;
    }
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // return approach_1(arr1, arr2, n, m);
        
        return approach_2(arr1, arr2, n, m);
    }
};


//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends