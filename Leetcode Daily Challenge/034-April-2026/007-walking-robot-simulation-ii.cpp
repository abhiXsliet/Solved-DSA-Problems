// https://leetcode.com/problems/walking-robot-simulation-ii/




#include <bits/stdc++.h>
using namespace std;

class Robot {
public:
    vector<vector<int>> position;
    int idx;
    bool movement;

    // TC : O(W + H)
    // SC : O(W + H)
    Robot(int width, int height) {
        idx = 0;
        movement = false;
        
        // bottom row (left - right) (East - '0')
        for (int w = 0; w < width; w ++) {
            position.push_back({w, 0, 0});
        }
        // far right column (down - up) (North - '1')
        for (int h = 1; h < height; h ++) {
            position.push_back({width - 1, h, 1});
        }
        // top left row (left - right) (West - '2')
        for (int w = width - 2; w >= 0; w --) {
            position.push_back({w, height - 1, 2});
        }
        // far left column (top - down) (South - '3')
        for (int h = height - 2; h > 0; h --) {
            position.push_back({0, h, 3});
        }
        position[0][2] = 3; // catch : after a perimeter round dir. changes to south
    }
    
    void step(int num) {
        movement = true;
        idx = (idx + num) % position.size();
    }
    
    vector<int> getPos() {
        return {position[idx][0], position[idx][1]};
    }
    
    string getDir() {
        if (!movement) return "East";
        int dir = position[idx][2];
        return dir == 0 ? "East" : dir == 1 ? "North" : dir == 2 ? "West" : "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */