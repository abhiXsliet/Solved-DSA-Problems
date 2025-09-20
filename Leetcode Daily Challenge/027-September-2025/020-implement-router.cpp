// https://leetcode.com/problems/implement-router/




#include <bits/stdc++.h>
using namespace std;

class Router {
public:
    int size;
    queue<vector<int>> q;
    unordered_map<int, vector<int>> mpp;   // {destination, {timestamps}}
    set<vector<int>> st;    // for duplicate check

    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    // TC : O(log(N)) Where N = No. of times this fn. gets invoked
    bool addPacket(int source, int destination, int timestamp) {
        if (st.count({source, destination, timestamp})) {
            return false;
        }

        if (q.size() >= size) {
            forwardPacket();
        }

        q.push({source, destination, timestamp});
        st.insert({source, destination, timestamp});
        mpp[destination].push_back(timestamp);

        return true;
    }
    
    // TC : O(1)
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        
        vector<int> res = q.front();
        q.pop();

        st.erase(res);
        
        vector<int> &timeStamps = mpp[res[1]];
        timeStamps.erase(begin(timeStamps));    // remove the first timeStamp only for forwardPacket

        return res;
    }
    
    // TC : O(N*log(K)) Where N = No. of times this fn. gets invoked & K = size of timeStamp vector
    int getCount(int destination, int startTime, int endTime) {
        vector<int> &vec = mpp[destination];

        auto low  = lower_bound(begin(vec), end(vec), startTime);
        auto high = upper_bound(begin(vec), end(vec), endTime);

        return (high - low);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */