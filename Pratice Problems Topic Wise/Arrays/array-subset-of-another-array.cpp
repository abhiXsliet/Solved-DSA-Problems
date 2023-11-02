// https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends

// TC = O( max(N*log(N), M*log(M)) )
string solve_brute(int a1[], int a2[], int n, int m) {
    if (n < m) return "No";
    
    sort(a1, a1 + n);
    sort(a2, a2 + m);
    
    int i = 0, j = 0;
    while(i < n && j < m) {
        if (a1[i] > a2[j]) {
            return "No";
        }
        else if (a1[i] == a2[j]) {
            i++, j++;
        }
        else {
            i++;
        }
    }
    return "Yes";
}

// TC = O(max(N, M))
// SC = O(N)
string solve_optimal(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mpp;
    
    for (int i = 0; i < n; i++)
        mpp[a1[i]]++;
        
    for (int i = 0; i < m; i++) {
        if (mpp.find(a2[i]) != mpp.end()) {
            if(mpp[a2[i]] > 0) mpp[a2[i]]--;
            else return "No";
        }
        else return "No";
    }
    return "Yes";
}

string isSubset(int a1[], int a2[], int n, int m) {
    
    // return solve_brute(a1, a2, n, m);
    
    return solve_optimal(a1, a2, n, m);
}