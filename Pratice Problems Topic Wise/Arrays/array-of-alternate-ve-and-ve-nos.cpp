// https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    // TC = O(N)
    // SC = O(N)
    void solve_brute(int arr[], int n) {
        vector<int> neg;
        vector<int> pos;
    
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) neg.push_back(arr[i]);
            else pos.push_back(arr[i]);
        }
    
        int ptr1 = 0;
        int ptr2 = 0;
        int idx = 0;
        bool flag = 1;
    
        while(ptr1 < pos.size() && ptr2 < neg.size()) {
            if (flag) {
                arr[idx++] = pos[ptr1++];
            }
            else {
                arr[idx++] = neg[ptr2++];
            }
            flag = !flag;
        }
    
        while (ptr1 < pos.size()) {
            arr[idx++] = pos[ptr1++];
        }
    
        while (ptr2 < neg.size()) {
            arr[idx++] = neg[ptr2++];
        }
    }
    
    // TC = O(N)
    // SC = O(N)
    void solve_better(int arr[], int n) {
        vector<int> pos;
        vector<int> neg;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) neg.push_back(arr[i]);
            else pos.push_back(arr[i]);
        }
        
        if (pos.size() > neg.size()) {
            // handle equal elements from both pos and neg
            for (int i = 0; i < neg.size(); i++) {
                arr[2*i]   = pos[i];
                arr[2*i+1] = neg[i];
            }
            // handle remaining pos elements
            int idx = 2*neg.size();
            for (int i = neg.size(); i < pos.size(); i++) {
                arr[idx++] = pos[i];
            }
        }
        else {
            //handle equal elements
            for (int i = 0; i < pos.size(); i++) {
                arr[2*i]   = pos[i];
                arr[2*i+1] = neg[i];
            }
            // handle remaining neg elements
            int idx = 2*pos.size();
            for (int i = pos.size(); i < neg.size(); i++) {
                arr[idx++] = neg[i];
            }
        }
    }
    
    void rotateRight(int arr[], int outOfPlace, int idx) {
        int temp = arr[idx];
        for (int i = idx; i > outOfPlace; i--) {
            arr[i] = arr[i - 1];
        }
        arr[outOfPlace] = temp;
    }
    
    // TC = O(N^2)
    // SC = O(1)
    void solve_optimal_with_const_space(int arr[], int n) {
        int outOfPlace = -1;
        // O(N)
        for (int i = 0; i < n; i++) {
            if (outOfPlace >= 0) {
                if(((arr[i] >= 0) && (arr[outOfPlace] < 0)) || 
                   ((arr[i] < 0 ) && (arr[outOfPlace] >= 0))) {
                    // O(N)
                    rotateRight(arr, outOfPlace, i);
                
                    if (i - outOfPlace >= 2) {
                        outOfPlace += 2;
                    }
                    else outOfPlace = -1;    
                } 
            }
            
            if (outOfPlace == -1) {
                // (!(i & 0x01)) -> checks the even index
                // (i & 0x01)    -> checks the odd index
                // -ve no. & at even-place or +ve no. & at odd place
                if (((arr[i]  < 0)  && (!(i & 0x01))) ||
                    ((arr[i] >= 0)  &&   (i & 0x01))) {
                    outOfPlace = i;
                }
            }
        }
    }
public:
	void rearrange(int arr[], int n) {
	   // solve_brute(arr, n);
	    
	   solve_better(arr, n);
	   
	//    solve_optimal_with_const_space(arr, n);
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends