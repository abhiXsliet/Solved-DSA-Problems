// https://leetcode.com/problems/longest-substring-without-repeating-characters/



#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
/*       
        // TC => O(2N)
        // SC => O(min(N, M)) where N is the length of the input string 's' 
        //                    and M is the size of the character set.
        int maxi = 0;
        int start = 0;
        int end = 0;
        unordered_set<char>st;
        while(start < s.length()) {
            if(st.find(s[start]) == st.end()) {
                maxi = max(maxi, (start - end + 1));
                st.insert(s[start++]);
            } 
            else {
                st.erase(s[end++]);
            }
        }
        return maxi;
         */



        // TC => O(N)
        // SC => O(1)
        int start = 0;
        int end  = 0;
        int maxi = 0;
        vector<int> count(256, 0);
        while(start < s.length()) {
            count[s[start]]++;
            //Reducing Window Size
            while(count[s[start]] > 1) {
                count[s[end]]--;
                end++;
            }

            maxi = max(maxi, start - end + 1);
            start++;
        }
        return maxi;
    }
};