// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(N)
    int solve_approach_1(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for (auto& num : arr) mpp[num] ++;
        
        // Create a vector of pairs from the map
        vector<pair<int, int>> vec(mpp.begin(), mpp.end());
        
        // Sort the vector by the frequency of the numbers
        sort(vec.begin(), vec.end(),  [&](auto a, auto b){
            return a.second < b.second;
        });
        
        // Print the sorted vector
        for (auto& i : vec) {
            if (k > 0) {
                if (i.second <= k) {
                    k -= i.second;
                    mpp.erase(i.first);
                }
            }
        }
        return mpp.size();
    }

    // TC : O(N * log(N))
    // SC : O(N)
    int solve_approach_2(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for (auto& num : arr) mpp[num] ++;
        
        vector<int> vec;
        
        for (auto& it : mpp) {
            vec.push_back(it.second);
        }

        sort(begin(vec), end(vec));
        
        for (int i = 0; i < vec.size(); i++) {
            k -= vec[i];

            if (k < 0) {
                return vec.size() - i;
            }
        }
        return 0; 
    }

    // TC : O(N * log(N)) -> Pushing 'n' elements in pq makes its time complexity as n*log(n)
    // SC : O(N)
    int solve_approach_3(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for (auto& num : arr) mpp[num] ++;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto& it : mpp) pq.push({it.second});
        
        while(!pq.empty()) {
            k -= pq.top();

            if (k < 0) {
                return pq.size();
            }

            pq.pop();
        }
        return 0; 
    }

    // TC : O(N)
    // SC : O(N)
    int solve_approach_4(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;

        for(int &x : arr) {
            mp[x]++;
        }

        vector<int> freqCount(n+1);
        //freqCount[i] = number of elements (types) having frequency = i

        int uniqueTypes = mp.size();

        for(auto &it : mp) {
            int freq = it.second;
            freqCount[freq]++;
        }


        for(int freq = 1; freq <= n; freq++) {

            int typesICanDelete = min(k/freq, freqCount[freq]);

            k -= (typesICanDelete * freq);

            uniqueTypes -= typesICanDelete;

            if(k <= freq) {
                return uniqueTypes;
            }
        }

        return 0;
    }
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // return solve_approach_1(arr, k);

        // return solve_approach_2(arr, k);

        // return solve_approach_3(arr, k);

        return solve_approach_4(arr, k);
    }
};
