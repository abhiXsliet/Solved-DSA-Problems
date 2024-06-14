// https://leetcode.com/problems/h-index/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(max-citations * N) ~= O(1000 * N)
    // SC : O(max-citations)     ~= O(1000)
    int brute(vector<int>& citations) {
        int n = citations.size();
        int max_citation = *max_element(begin(citations), end(citations));
        vector<int> count_citation(max_citation + 1, 0);
        for (int i = 0; i <= max_citation; i ++) {
            for (int j = 0; j < n; j ++) {
                if (citations[j] >= i) {
                    count_citation[i] ++;
                }
            }
        }
        int hIdx = 0;
        for (int i = 0; i < count_citation.size(); i++) {
            if (count_citation[i] >= i) {
                hIdx = max(hIdx, i);
            } 
        }
        return hIdx;
    }

    // TC : O(N)
    // SC : O(N)
    int better_1(vector<int>& citations) {
        int n = citations.size();
        vector<int> count_citation(n + 1, 0);   // suffix-sum
        
        for (int i = 0; i < n; i ++) {
            if (citations[i] < n) 
                count_citation[citations[i]] ++;
            else // >= n
                count_citation[n] ++;
        }

        for (int i = n - 1; i >= 0; i --) {
            count_citation[i] += count_citation[i + 1];
        }

        int hIdx = 0;
        for (int i = 0; i <= n; i++) {
            if (count_citation[i] >= i) {
                hIdx = max(hIdx, i);
            } 
        }
        return hIdx;
    }

    // TC : O(N)
    // SC : O(N)
    int better_2(vector<int>& citations) {
        int n = citations.size();
        vector<int> count_citation(n + 1, 0);   // suffix-sum
        
        for (int i = 0; i < n; i ++) {
            if (citations[i] < n) 
                count_citation[citations[i]] ++;
            else // >= n
                count_citation[n] ++;
        }

        // Maintain a suffixSum to remove the extra loop for suffix Calculation
        int suffixSum = 0;
        int hIdx = 0;
        for (int i = n; i >= 0; i --) {
            if (count_citation[i] + suffixSum >= i) 
                hIdx = max(hIdx, i);

            suffixSum += count_citation[i];
        }
        return hIdx;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int optimal_1(vector<int>& citations) {
        int n = citations.size();
        // sort in decreasing to the highest citations at first
        sort(begin(citations), end(citations), greater<int>());
        
        int low = 0, high = n - 1, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Check if there are at least (mid + 1) papers with at least (mid + 1) citations
            if (citations[mid] >= mid + 1) {
                ans = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int optimal_2(vector<int>& citations) {
        int n = citations.size();
        sort(begin(citations), end(citations));
        
        int low = 0, high = n - 1, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Check if there are at least (mid + 1) papers with at least (mid + 1) citations
            if (citations[mid] >= n - mid) {
                ans  = n - mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
public:
    int hIndex(vector<int>& citations) {
        // return brute(citations);

        // return better_1(citations);

        // return better_2(citations);

        // return optimal_1(citations);

        return optimal_2(citations);
    }
};