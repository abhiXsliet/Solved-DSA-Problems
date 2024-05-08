// https://leetcode.com/problems/relative-ranks/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(N)
    vector<string> approach_1(vector<int>& score) {
        int n = score.size();
        
        vector<string> result(n);
        
        unordered_map<int, int> mp;
        
         
        for(int i = 0; i < n; i++) {
            mp[score[i]] = i; //ith athelete
        }
        
        sort(begin(score), end(score), greater<int>()); //descending
        
        
        for(int i = 0; i < n; i++) {
            
            if(i == 0) { //1st Rank wala athelete
                int ath = mp[score[i]];
                result[ath] = "Gold Medal";
            } else if(i == 1) {
                int ath = mp[score[i]];
                result[ath] = "Silver Medal";
            } else if(i == 2) {
                int ath = mp[score[i]];
                result[ath] = "Bronze Medal";
            } else {
                int ath = mp[score[i]];
                result[ath] = to_string(i+1);
            }
            
        }
        
        return result;
    }

    // TC : O(N * log(N))
    // SC : O(N)
    vector<string> approach_2(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        vector<string> ans(n, "");
        int cnt = 1;
        while(!pq.empty()) {
            int topEl = pq.top().first;
            int topId = pq.top().second;
            pq.pop();

            if (cnt == 1) ans[topId] = "Gold Medal";
            else if (cnt == 2) ans[topId] = "Silver Medal";
            else if (cnt == 3) ans[topId] = "Bronze Medal";
            else ans[topId] = to_string(cnt);

            cnt += 1;
        }
        return ans;
    }

    // T.C : O(n)
    // S.C : O(max_score)
    vector<string> approach_3(vector<int>& score) {
        int n = score.size();
        vector<string> result(n);
        
        int M = *max_element(begin(score), end(score));
        
        vector<int> mp(M+1, -1);
        
        for(int i = 0; i < n; i++) {
            mp[score[i]] = i;
        }
        
        
        int rank = 1;
        
        for(int s = M; s >= 0; s--) {
            
            if(mp[s] != -1) {
                int athlete = mp[s];
                
                if(rank == 1) {
                    result[athlete] = "Gold Medal";
                } else if(rank == 2) {
                    result[athlete] = "Silver Medal";
                } else if(rank == 3) {
                    result[athlete] = "Bronze Medal";
                } else {
                    result[athlete] = to_string(rank);
                }
                
                rank++;
            }
            
        }
        
        return result;
    }
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // return approach_1(score);

        // return approach_2(score);

        return approach_3(score);
    }
};