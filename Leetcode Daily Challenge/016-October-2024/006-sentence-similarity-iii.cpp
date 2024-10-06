// https://leetcode.com/problems/sentence-similarity-iii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M + N)
    // SC : O(M + N)
    bool approach_1(string sentence1, string sentence2) {
        int m = sentence1.length(), n = sentence2.length();
        
        if (n > m) {
            swap(sentence1, sentence2);
        }

        vector<string> sent1;
        vector<string> sent2;

        istringstream iss1(sentence1);
        string str;
        while (iss1 >> str) sent1.push_back(str);   

        // while (getline(iss1, str, ' ')) {
        //     sent1.push_back(str);
        // }

        istringstream iss2(sentence2);
        str = "";
        while (iss2 >> str) sent2.push_back(str); 

        // while (getline(iss2, str, ' ')) {
        //     sent2.push_back(str);
        // }

        int i = 0, j = sent1.size() - 1;
        int k = 0, l = sent2.size() - 1;

        while (k <= l) {
            if (sent2[k] == sent1[i]) {
                k ++, i ++;
            } else if (sent2[l] == sent1[j]) {
                l --, j --;
            } else {
                return false;
            }
        }
        return true;
    }

    // TC : O(M + N)
    // SC : O(M + N)
    bool approach_2(string sentence1, string sentence2) {
        int m = sentence1.length(), n = sentence2.length();
        
        if (n > m) {
            swap(sentence1, sentence2);
        }

        deque<string> ds1, ds2;

        istringstream iss1(sentence1);
        string str;
        while (iss1 >> str) ds1.push_back(str);   

        istringstream iss2(sentence2);
        str = "";
        while (iss2 >> str) ds2.push_back(str); 

        while (!ds2.empty() && !ds1.empty()) {
            if (ds2.front() == ds1.front()) {
                ds2.pop_front();
                ds1.pop_front();
            } else if (ds2.back() == ds1.back()) {
                ds2.pop_back();
                ds1.pop_back();
            } else {
                return false;
            }
        }
        return true;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // return approach_1(sentence1, sentence2);

        return approach_2(sentence1, sentence2);
    }
};