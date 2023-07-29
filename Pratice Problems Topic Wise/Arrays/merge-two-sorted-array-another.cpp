#include <bits/stdc++.h>
using namespace std;

//TC => O((n+m) * log(n+m))
//SC => O(n+m)
void merge_Brute(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> arr(n+m);
    for(int i = 0; i < m; i++) {
        arr[i] = nums1[i];
    }
    for(int i = m; i < n+m; i++) arr[i] = nums2[i-m];
    nums1.resize(n+m);
    for(int i = 0; i < nums1.size(); i++) nums1[i] = arr[i];
    sort(nums1.begin(), nums1.end());
}

// TC => O(n+m)
// SC => O(1)
void merge_Optimal(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    for(int i = 0; i < m; i++) {
        cout << nums1[i] << " " ;
    }
    nums1.resize(m+n);
    for(int i = m; i < n+m; i++) {
        nums1[i] = nums2[i-m];
    }
    sort(nums1.begin(), nums1.end());
}

int main() {
    
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    // merge_Brute(nums1, nums2);
    for(int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }

    cout << endl;
    merge_Optimal(nums1, nums2);
    for(int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }

    cout << endl << endl ;
    return 0;
}
