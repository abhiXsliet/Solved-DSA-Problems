// https://leetcode.com/problems/find-all-anagrams-in-a-string/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(p.size() > s.size()) return {};
        
        vector<int>p_hash(26, 0);
        vector<int>s_hash(26, 0);
        vector<int> ans;

        for(int i=0; i<p.size(); i++) {
            s_hash[s[i]-'a']++;
            p_hash[p[i]-'a']++;
        }

        if(p_hash == s_hash) ans.push_back(0);

        for(int i=p.size(); i<s.size(); i++) {
            s_hash[s[i-p.size()] - 'a']--;
            s_hash[s[i]-'a']++;
            if(s_hash == p_hash) ans.push_back(i+1 - p.size());
        }
        return ans;
    }
};