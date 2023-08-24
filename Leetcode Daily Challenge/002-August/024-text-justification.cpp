// https://leetcode.com/problems/text-justification/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getFinalWord(int i, int j, int slots_bw_words, int extra_slots_bw_words, 
                            vector<string>& words, int maxWidth) {
        string s;

        for(int k = i; k < j; k++) {
            s += words[k];

            if(k == j-1)
                continue;

            for(int space = 1; space <= slots_bw_words; space++)
                s += " ";

            if(extra_slots_bw_words > 0) {
                s += " ";
                extra_slots_bw_words--;
            }
        }

        while(s.length() < maxWidth) {
            s += " ";
        }
        
        return s;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n     = words.size();
        int i     = 0;
        
        while(i < n) {
            int lettersCount = words[i].length();
            int j            = i+1;
            int slots   = 0;
            
            while(j < n && slots + lettersCount + words[j].length() + 1 <= maxWidth) {
                lettersCount += words[j].length();
                slots   += 1;
                j++;
            }
            
            int remainingSlots = maxWidth - lettersCount;
            
            
            int slots_bw_words = slots == 0 ? 0 : remainingSlots / slots;
            int extra_slots_bw_words    = slots == 0 ? 0 : remainingSlots % slots;
            
            if(j == n) { //Means we are on last line - Left justfied
                slots_bw_words = 1;
                extra_slots_bw_words    = 0;
            }
            
            
            result.push_back(getFinalWord(i, j, 
                    slots_bw_words, extra_slots_bw_words, words, maxWidth));
            i = j;
        }
        
        return result;
    }
};