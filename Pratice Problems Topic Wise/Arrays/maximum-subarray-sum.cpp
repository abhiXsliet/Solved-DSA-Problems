#include <bits/stdc++.h>
using namespace std;

// TC => O(N^3) where N is the length of the vector
// SC => O(1)
int maxSubArraySum_Brute1(vector<int>& arr) {
    int n = arr.size();
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k < j; k++) {
                sum += arr[k];
                maxi = max(maxi, sum);
            }
        }
    }
    return maxi;
}

// TC => O(N^2)
// SC => O(1)
int maxSubArraySum_Brute2(vector<int>& arr) {
    int n = arr.size();
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// TC => O(N)
// SC => O(1)
int maxSubArraySum_kadaneAlgo(vector<int>& arr) {
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if(sum > maxi) maxi = max(maxi, sum);
        if(sum < 0) sum = 0;
    }
    return maxi;
}

// TC => O(N)
// SC => O(1)
int maxSubArraySum_kadaneAlgo_followUp(vector<int>& arr) {
    int maxi = INT_MIN;
    int sum = 0;
    int ansStart = -1;
    int ansEnd = -1;
    int start = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum == 0) {
            int start = i;
        }
        if(sum > maxi) {
            maxi = max(maxi, sum);
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }
    cout << "Subarray is : [ ";
    for(int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i];
        if(i!=ansEnd)
            cout << " ";
    }
    cout << " ]";
    cout << endl;

    return maxi;
}

int main() {
    vector<int> arr = {1, 2, -3};

    cout << "\nMaximum sum of the subarray : " << maxSubArraySum_Brute1(arr) << endl;
    cout << "Maximum sum of the subarray : " << maxSubArraySum_Brute2(arr) << endl;
    cout << "Maximum sum of the subarray : " << maxSubArraySum_kadaneAlgo(arr) << endl;
    cout << "Maximum sum of the subarray : " << maxSubArraySum_kadaneAlgo_followUp(arr) << endl;

    cout << endl;
    return 0;
}