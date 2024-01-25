// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

typedef long long ll;

// TC : O(N)
// SC : O(N)
vector<ll> solve_approach_1(ll A[], ll N, ll K) {
    deque<ll> dq;
    vector<ll> ans;
    
    //step 1 -> process first k window side
    for(int i=0; i<K; i++)
    {
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    
    //step 2 -> store ans for first k sized window
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);
    }
    
    //step 3 -> process for the remaining window
    for(int i=K; i<N; i++){
        
        //removal logic
        if(!dq.empty() && i-dq.front() >= K){
            dq.pop_front();
        }
        
        //addition logic
        if(A[i] < 0){
            dq.push_back(i);
        }
        
        //ans store
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
}

// TC : O(N)
// SC : O(N)
vector<ll> solve_approach_2(ll arr[], ll n, ll k) {
    vector<ll> result;
    queue<ll> storeNeg;
    int i = 0, j = 0;
    while (j < n) {
        if (arr[j] < 0) storeNeg.push(arr[j]);
        if (j - i + 1 > k) {
            if (!storeNeg.empty() && arr[i] == storeNeg.front()) {
                storeNeg.pop();
            }
            i++;
        }
        if (j - i + 1 == k) {
            if (!storeNeg.empty()) {
                result.push_back(storeNeg.front());
            }
            else result.push_back(0);
        }
        j ++;
    }
    return result;
}

vector<ll> printFirstNegativeInteger(ll A[], ll N, ll K) {
    // return solve_approach_1(A, N, K);
    
    return solve_approach_2(A, N, K);
}