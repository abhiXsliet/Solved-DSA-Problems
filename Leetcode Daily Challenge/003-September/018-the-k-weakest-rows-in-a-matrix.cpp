// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/


#include <bits/stdc++.h>
using namespace std;


class Solution {
    typedef pair<int, int> P;

    // TC = O( M * N )
    // SC = O( M )
    vector<int> solve_brute(vector<vector<int>>& mat, int k) {
        vector<P> store;
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            int cntOne = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) cntOne++;
                else break;
            }
            store.push_back({i, cntOne});
        }

        auto cmp = [&] (P a, P b) {
            if (a.first < b.first && a.second == b.second) return true;
            else return a.second < b.second;
        };
        
        sort(begin(store), end(store), cmp);

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(store[i].first);
        }

        return result;
    }

    int binarySearch(vector<int>& row, int low, int high) {
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (row[mid] == 1) {
                res = mid;
                low = mid + 1;
            } 
            else high = mid - 1;
        }
        return (res + 1);
    }
    
    // TC = O( M * log(N) ) + O( M * log(M) ) + O(K)
    // SC = O( M )
    vector<int> solve_better(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        // O(M) space
        vector<P> countOnes; // {num_of_ones_in_each_row, row}

        for (int row = 0; row < m; row++) {
                                        // O(M * log(N))
            int num_of_ones_in_each_row = binarySearch(mat[row], 0, n - 1);
            
            countOnes.push_back({num_of_ones_in_each_row, row});
        }

        // O(M * log(M))
        sort (begin(countOnes), end(countOnes));

        // O(K)
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = countOnes[i].second;
        }
        return result;
    }

    // TC = O( M * log(N) ) + O( M * log(K) ) + O(K)
    // SC = O( K )
    vector<int> solve_optimal(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        priority_queue<P> pq; 
        
        for (int row = 0; row < m; row++) {
                                            // ( M * log(N) )
            int num_of_ones_in_each_row = binarySearch(mat[row], 0, n - 1);

            // ( M * log(K) )
            pq.push({num_of_ones_in_each_row, row});

            if (pq.size() > k) pq.pop();
        }

        // O( K )
        vector<int> result(k);
        int j = k - 1;

        while (!pq.empty()) {
            result[j] = pq.top().second;
            pq.pop();

            j--;
        }

        return result;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        // return solve_brute(mat, k);

        // return solve_better(mat, k);

        return solve_optimal(mat, k);
    }
};