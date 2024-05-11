// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * (N + K*logK))
    // SC : O(N + K)
    double solve_brute(vector<int>& quality, vector<int>& mini_wage, int k) {
        int n = quality.size();
        double result = DBL_MAX;

        for (int manager = 0; manager < n; manager ++) {

            double managerRatio = (double)mini_wage[manager]/quality[manager];

            vector<double> group;

            for (int worker = 0; worker < n; worker ++) {

                double worker_wage = managerRatio * quality[worker];
                
                if (worker_wage >= mini_wage[worker]) {
                    group.push_back(worker_wage);
                }
            }

            if (group.size() < k) continue;

            priority_queue<double, vector<double>> pq;
            double sum_wage = 0;

            for (double& wage : group) {
                sum_wage += wage;
                pq.push(wage);

                if (pq.size() > k) {
                    sum_wage -= pq.top();
                    pq.pop();
                }
            }
            result = min(result, sum_wage);
        }
        return result;
    }

    // TC : O(N*logN + N * (N + K*logK)) - This is worst case when no one got eliminated 
    // SC : O(N + K)
    double solve_better(vector<int>& quality, vector<int>& mini_wage, int k) {
        int n = quality.size();
        double result = DBL_MAX;

        vector<pair<double, int>> workers_ratio;
        for (int worker = 0; worker < n; worker ++) {
            workers_ratio.push_back({(double)mini_wage[worker]/quality[worker], quality[worker]});
        }

        sort(begin(workers_ratio), end(workers_ratio));

        for (int manager = k - 1; manager < n; manager ++) {

            double managerRatio = workers_ratio[manager].first;

            vector<double> group;

            for (int worker = 0; worker <= manager; worker ++) {

                double worker_wage = managerRatio * workers_ratio[worker].second;
                group.push_back(worker_wage);
            }

            priority_queue<double, vector<double>> pq;
            double sum_wage = 0;

            for (double& wage : group) {
                sum_wage += wage;
                pq.push(wage);

                if (pq.size() > k) {
                    sum_wage -= pq.top();
                    pq.pop();
                }
            }

            result = min(result, sum_wage);
        }

        return result;
    }

    // TC : O(N*logN + K*logK + N*log(K))
    // SC : O(N + K)
    double solve_optimal(vector<int>& quality, vector<int>& mini_wage, int k) {
        int n = quality.size();

        vector<pair<double, int>> workers_ratio;
        for (int worker = 0; worker < n; worker ++) {
            workers_ratio.push_back({(double)mini_wage[worker]/quality[worker], quality[worker]});
        }

        sort(begin(workers_ratio), end(workers_ratio));
            
        priority_queue<int, vector<int>> pq;
        double sum_quality = 0;
        
        for (int worker = 0; worker < k; worker ++) {
            pq.push(workers_ratio[worker].second);
            sum_quality += workers_ratio[worker].second;
        }

        double managerRatio = workers_ratio[k - 1].first;
        double result       = managerRatio * sum_quality;

        for (int manager = k; manager < n; manager ++) {

            managerRatio = workers_ratio[manager].first;

            pq.push(workers_ratio[manager].second);
            sum_quality += workers_ratio[manager].second;

            if (pq.size() > k) {
                sum_quality -= pq.top();
                pq.pop();
            }

            result = min(result, managerRatio * sum_quality);
        }
        return result;
    }
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& mini_wage, int k) {
        // return solve_brute(quality, mini_wage, k);

        // return solve_better(quality, mini_wage, k);     // Minimal Improvement

        return solve_optimal(quality, mini_wage, k);
    }
};