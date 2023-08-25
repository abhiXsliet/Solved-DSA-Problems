// https://leetcode.com/problems/reorganize-string/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string reOgranizeString_Approach1 (string s, string& result) {
        vector<int> count(26, 0);
        int n = s.length();

        for(auto &ch : s) {
            count[ch - 'a']++;
            
            if(count[ch - 'a'] > (n+1)/2)
                return "";
        }

        // Max Heap
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) pq.push({count[i], 'a'+i});
        }

        // O(k * log(k))
        // O(n * log(k)) or O(n * log(n)) -> at worst
        while(pq.size() >= 2) {
            auto pair1 = pq.top(); // O( log(k) ) -> O( log(26) )
            pq.pop();

            auto pair2 = pq.top(); // O( log(k) )-> O( log(26) )
            pq.pop();

            result.push_back(pair1.second); pair1.first--; // n times
            result.push_back(pair2.second); pair2.first--; // n times

            if(pair1.first > 0) pq.push(pair1);
            if(pair2.first > 0) pq.push(pair2);
        }

        if(!pq.empty()) result.push_back(pq.top().second);

        return result;
    }

    string reOrganizeString_Approach2(string s, string& result) {
        vector<int> count(26, 0);
        int n = s.length();

        int maxFreq = 0;
        char maxChar;

        for(auto &ch : s) {
            count[ch - 'a']++;

            if(count[ch - 'a'] > maxFreq) {
                maxFreq = count[ch - 'a'];
                maxChar = ch;
            }
            
            if(count[ch - 'a'] > (n+1)/2)
                return "";
        }

        int index = 0;
        result = s;
        while(count[maxChar  - 'a'] > 0) {
            result[index] = maxChar;
            index += 2; // max char on Alternate 
            count[maxChar - 'a']--;
        }

        // placing the left char on the correct position
        for(char ch = 'a'; ch <= 'z'; ch++) {
            while(count[ch - 'a'] > 0) {
                
                if(index >= n) index = 1;

                result[index] = ch;
                index += 2;
                count[ch - 'a']--;
            }
        }
        return result;
    }

public:
    string reorganizeString(string s) {
        int n = s.length();
        
        string result = "";
        
        // // Approach - 1 -> Using Max Heap
        // // TC = O(n * log(k))
        // // SC = O(n) -> to store the result
        // return reOgranizeString_Approach1(s, result);


        // // Approach - 2 -> Max Char at the Alternate position
        // // TC = O(n)
        // // SC = O(n) -> to store the result
        return reOrganizeString_Approach2(s, result);
    }
};