// https://www.codingninjas.com/studio/problems/find-the-winner_1095656


#include <bits/stdc++.h> 
using namespace std;

string getWinner(vector < string > & votes) {
    string ans;
    int cnt = 0;
    map<string, int> mpp;
    for(auto& names : votes) {
        mpp[names]++;
    }
    for(auto& i:mpp) {
        if(i.second > cnt) {
            cnt = i.second;
            ans = i.first;
        } else if(i.second == cnt) {
            if(i.first < ans) {
                ans = i.first;
            }
        }
    }
    return ans;
}
