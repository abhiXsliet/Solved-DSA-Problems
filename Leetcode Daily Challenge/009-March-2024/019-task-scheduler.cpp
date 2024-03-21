// https://leetcode.com/problems/task-scheduler/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = total numbers of task
    // SC : O(26) ~= O(1)
    int solve_1(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for(auto& task : tasks) {
            mpp[task]++;
        }

        // Create a max heap to store the tasks sorted by their frequencies
        priority_queue<int> maxHeap;
        for(auto it : mpp) {
            maxHeap.push(it.second);
        }

        int time = 0;
        while(!maxHeap.empty()) {
            int interval = n + 1;
            vector<int> temp;

            // Fill the interval with the next high frequency task
            while(interval > 0 && !maxHeap.empty()) {
                temp.push_back(maxHeap.top());
                maxHeap.pop();
                interval--;
                time++;
            }

            // Push the remaining tasks back into the max heap
            for(auto it : temp) {
                if(--it > 0) {
                    maxHeap.push(it);
                }
            }

            // If there are still tasks in the max heap, add idle time
            if(!maxHeap.empty()) {
                time += interval;
            }
        }

        return time;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_2(vector<char>& tasks, int n) {
        // Create a frequency vector to count the occurrence of each task
        vector<int> freq(26, 0);
        for(auto& task : tasks) {
            freq[task - 'A'] ++;
        }

        // Create a priority queue to store the frequencies
        priority_queue<int> pq;
        int time = 0;

        // Push the frequencies into the priority queue
        for (auto& f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }

        // While there are still tasks left
        while(!pq.empty()) {
            vector<int> temp;
            // Perform n+1 tasks at once
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top(); pq.pop();
                    freq --;
                    temp.push_back(freq);
                }
            }

            // If a task is still left, push it back into the queue
            for (int& f : temp) {
                if (f > 0) {
                    pq.push(f);
                }
            }

            // If all tasks are done, add the actual number of tasks done
            // Otherwise, add n+1 (as idle time is considered)
            if (pq.empty()) {
                time += temp.size();
            }
            else {
                time += n + 1;
            }
        }
        // Return the total time taken
        return time;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int solve_3(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto& task : tasks) {
            freq[task - 'A'] ++;
        }
        
        sort(rbegin(freq), rend(freq));
        
        int maxChar     = freq[0];
        int separations = maxChar - 1;       // spaces b/w two similar char
        int slots       = separations * n;   // Available Slots

        for (int i = 1; i < 26; i++) {
            slots -= min(freq[i], separations);
        }

        if (slots > 0) {
            return tasks.size() + slots;
        }

        return tasks.size();
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        // return solve_1(tasks, n);

        // return solve_2(tasks, n);

        return solve_3(tasks, n);    // Greedy
    }
};