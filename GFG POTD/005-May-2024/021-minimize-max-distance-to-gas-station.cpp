// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:  
    // TC : O(K*N)
    // SC : O(N)
    double solve_brute(vector<int>& stations, int k) {
        int n = stations.size();
        vector<int> sectors(n - 1, 0); // How Many Sections Obtained after placing 'k' gas-stations
        for(int gasStation = 1; gasStation <= k; gasStation ++) {
            int maxIdx = -1;
            double maxSectionLen = -1;
            for (int i = 0; i < n - 1; i ++) {
                double diff = stations[i + 1] - stations[i];
                double sectionLen = diff / (double) (sectors[i] + 1);
                
                if (sectionLen > maxSectionLen) {
                    maxSectionLen = sectionLen;
                    maxIdx        = i;
                }
            }
            sectors[maxIdx] ++;
        }
        double result = -1;
        for (int i = 0; i < n - 1; i ++) {
            double diff = (stations[i + 1] - stations[i]);
            double sectionLen = diff / (double) (sectors[i] + 1);
            result = max(result, sectionLen);
        }
    }
    
    // TC : O( max(N*log(N), K*log(N)) )
    // SC : O(N)
    double solve_better(vector<int>& stations, int k) {
        int n = stations.size();
        vector<int> sectors(n - 1, 0);
        priority_queue<pair<double, int>> pq;
        
        for (int i = 0; i < n - 1; i ++) {
            pq.push({stations[i + 1] - stations[i], i});
        }
        
        for (int gasStations = 1; gasStations <= k; gasStations ++) {
            int sectionIdx = pq.top().second;
            pq.pop();
            
            sectors[sectionIdx] ++;
            
            double initialDiff = stations[sectionIdx + 1] - stations[sectionIdx];
            double newDiff     = initialDiff / (double)(sectors[sectionIdx] + 1);
            
            pq.push({newDiff, sectionIdx});
        }
        
        return pq.top().first;
    }
    
    int getNoOfGasStations(double dist, vector<int>& stations, int n) {
        int cnt = 0;
        for (int i = 1; i < n; i ++) {
            int numberInBetween = ((stations[i] - stations[i - 1]) / dist);
            if ((stations[i] - stations[i - 1]) / dist == numberInBetween * dist) {
                numberInBetween --;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }
    
    // TC : O( N*log(K) )
    // SC : O(N)
    double solve_optimal(vector<int>& stations, int k) {
        int n = stations.size();
        
        double low = 0, high = 0;
        
        for (int i = 0; i < n - 1; i ++) {
            high = max(high, (double)(stations[i + 1] - stations[i]));
        }
        
        double diff = 1e-6;
        while(high - low > diff) {
            double mid = (low + high) / 2.0;
            
            int cnt = getNoOfGasStations(mid, stations, n);
            
            if (cnt > k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        return high;
    }
  public:
    double findSmallestMaxDist(vector<int>& stations, int k) {
        // return solve_brute(stations, k);
        
        // return solve_better(stations, k);
        
        return solve_optimal(stations, k);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends