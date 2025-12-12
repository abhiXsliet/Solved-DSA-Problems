// https://leetcode.com/problems/count-mentions-per-user/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void applyMessageEvent(vector<string>event, vector<int>&mentionCount, vector<int>&offlineTime){

        int timestamp = stoi(event[1]);

        vector<string> ids;

        stringstream ss(event[2]);

        string token;
        while(ss >> token){
            ids.push_back(token);
        }

        for(string id : ids) {
            if(id == "ALL") {
                for(int i = 0; i<mentionCount.size(); i++) {
                    mentionCount[i]++;
                }
            } else if(id == "HERE") {
                for(int i = 0; i < mentionCount.size(); i++){
                    if(offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp){
                        mentionCount[i]++;
                    }
                }
            } else {
                mentionCount[stoi(id.substr(2))]++; 
            }
        }

    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>mentionCount(numberOfUsers);
        vector<int>offlineTime(numberOfUsers);

        auto lambda=[](vector<string>& vec1, vector<string>& vec2) {
            int t1 = stoi(vec1[1]);
            int t2 = stoi(vec2[1]);

            if(t1 == t2) {
                return vec1[0][1] > vec2[0][1]; 
            }

            return t1 < t2;
        };

        sort(events.begin(), events.end(), lambda);

        for(vector<string>event: events){
            if(event[0] == "MESSAGE") {
                applyMessageEvent(event, mentionCount, offlineTime);
            }
            else if(event[0] == "OFFLINE") {
                int timestamp = stoi(event[1]);
                int id = stoi(event[2]);
                offlineTime[id] = timestamp;
            }
        }

        return mentionCount;
    }
};