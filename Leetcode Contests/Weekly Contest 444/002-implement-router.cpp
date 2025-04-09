// https://leetcode.com/contest/weekly-contest-444/problems/implement-router/




#include <bits/stdc++.h>
using namespace std;

class Router {
private:
    int cap = 0;
    unordered_map<int, vector<int>> mpp;    // {destination, {timestamp}}
    set<vector<int>> st;    // {source, destination, timestamp}
    queue<vector<int>> q;   // {source, destination, timestamp}

    void removePacket() {
        auto pkt = q.front();
        st.erase(pkt);
        int src = pkt[0], dest = pkt[1], tStamp = pkt[2];
        *lower_bound(begin(mpp[dest]), end(mpp[dest]), tStamp) = 0;
        q.pop();
    }
public:
    Router(int memoryLimit) {
        cap = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        
        if (st.count(packet)) return false;
        if (q.size() == cap) removePacket();
        
        st.insert(packet);
        q.push(packet);
        mpp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        
        vector<int> pkt = q.front();

        removePacket();
        
        return pkt;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &tStamp = mpp[destination];
        return upper_bound(begin(tStamp), end(tStamp), endTime) - lower_bound(begin(tStamp), end(tStamp) ,startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */