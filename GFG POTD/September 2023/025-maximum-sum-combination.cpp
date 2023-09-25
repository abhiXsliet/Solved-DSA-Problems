// https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    // TC = O( N * N )
    // SC = O( N * N )
    vector<int> solve_brute(int N, int K, vector<int> &A, vector<int> &B) {
        vector<int> store(N*N, 0);
        int k = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                store[k++] = (A[i] + B[j]);
            }
        }
        
        sort(begin(store), end(store));
        int idx = store.size() - 1;
        
        vector<int> result(K, 0);
        for (int i = 0; i < K; i++) {
            result[i] = store[idx--];
        }
        
        return result;
    }
    
    // TC = O(N * log(N))
    // SC = O( N )
    vector<int> solve_optimal(int N, int K, vector<int> &A, vector<int> &B) {
        vector<int> result;
        
        sort (begin(A), end(A));
        sort (begin(B), end(B));
        
        priority_queue<pair<int, pair<int, int>>> pq;   // sum , {idx1, idx2}
        set<pair<int, int>> st;         // {idx1, idx2}
        
        pq.push({A.back() + B.back(), {N - 1, N - 1}});
        st.insert({N - 1, N - 1});
        
        while (K--) {
            auto p   = pq.top();
            int sum  = p.first;
            int idx1 = p.second.first;
            int idx2 = p.second.second;
            
            result.push_back(sum);
            pq.pop();
            
            if (st.find({idx1 - 1, idx2}) == st.end()) {
                pq.push({A[idx1 - 1] + B[idx2], {idx1 - 1, idx2}});
                st.insert({idx1 - 1, idx2});
            }
            
            if (st.find({idx1, idx2 - 1}) == st.end()) {
                pq.push({A[idx1] + B[idx2 - 1], {idx1, idx2 - 1}});
                st.insert({idx1, idx2 - 1});
            }
        }
        
        return result;
    }
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // return solve_brute(N, K, A, B);
        
        return solve_optimal(N, K, A, B);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends