// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1




//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

/*You are required to complete this method*/
class Solution {
  private:
    // TC : O(N^2)
    // SC : O(1)
    int approach_1(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        
        for (int i = 0; i < n; i ++) {
            int gasReq = gas[i] - cost[i];
            if (gasReq >= 0) {
                int reach = i;
                for (int j = i + 1; j < 2*n; j ++) {
                    gasReq += (gas[j % n] - cost[j % n]);
                    if (gasReq < 0) {
                        break;
                    } 
                    if (reach == (j % n)) 
                        return i;
                }
            }
        }
        return -1;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int totalGas  = accumulate(begin(gas), end(gas), 0);
        int totalCost = accumulate(begin(cost), end(cost), 0);
        if (totalCost > totalGas) return -1;
        
        totalGas = 0, totalCost = 0;
        int minStartIdx = 0;
        for (int i = 0; i < n; i ++) {
            totalGas += (gas[i] - cost[i]);
            if (totalGas < 0) { // ith can't be the answer since it reduces the totalGas to -ve
                totalGas = 0;
                minStartIdx = (i + 1);  
            }
        }
        return minStartIdx;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
    
        int totalGas = 0, deficit = 0;
        int minStartIdx = 0;
        for (int i = 0; i < n; i ++) {
            totalGas += (gas[i] - cost[i]);
            if (totalGas < 0) { // ith can't be the answer since it reduces the totalGas to -ve
                deficit += totalGas;
                totalGas = 0;
                minStartIdx = (i + 1);  
            }
        }
        return (deficit + totalGas >= 0) ? minStartIdx : -1;
    }
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // return approach_1(gas, cost);   // BRUTE : Try from each index-i
        // return approach_2(gas, cost);
         return approach_3(gas, cost);  // One pass
    }
};

//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends