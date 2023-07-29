//https://leetcode.com/problems/minimum-index-of-a-valid-split/


#include <iostream>
#include <vector>
using namespace std;

int getMajorityElement(vector<int>& arr) {
    int cnt = 0;
    int el;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        if(cnt == 0) {
            cnt = 1;
            el = arr[i];
        } else if(el == arr[i]) cnt++;
        else cnt--;
    }
    return el;
}

bool isMajority(int element, int freq) {
    return (2 * (element)) > freq;
}

int main() {
    vector<int> arr = {2,1,3,1,1,1,7,1,2,1}; // 1, 2, 2, 2
    int n = arr.size();
    int majorityEle = getMajorityElement(arr);
    int majorityCnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == majorityEle) majorityCnt++;
    }

    int ans = -1;
    int currCount = 0;
    int firstSubArrayLen = 0;
    for(int i = 0; i < n - 1; i++) {
        firstSubArrayLen++;
        if(arr[i] == majorityEle) currCount++;
        if( isMajority(currCount, firstSubArrayLen) && 
            isMajority(majorityCnt - currCount, n - firstSubArrayLen ) ) {
                ans = i;
                break;
        }
    }
    cout << "\nValid Index of Split is : " << ans << endl;
    
    cout << endl;
    return 0;
}
