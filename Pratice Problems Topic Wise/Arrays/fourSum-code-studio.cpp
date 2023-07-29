// https://www.codingninjas.com/studio/problems/4sum_5713771



#include<bits/stdc++.h>
using namespace std;

/* 
// TLE 
// Time Complexity => O(N^3 * log(N))
// Space Complexity => 2*O(no. of quadruplets) -> one for set and one for returning answer
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> st;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            set<long long>has;
            for(int k=j+1; k<n; k++) {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                int fourthEle = target - (sum);
                if(has.find(fourthEle) != has.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(fourthEle)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                has.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

 */


// Time Complexity => O(N^3)
// Space Complexity => O(1) -> for algorithm
// O(no. of quadruplets) for returning answer
vector<vector<int>> fourSum(vector<int>& nums, int target) {

    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1; j<n; j++) {
            if(j > i+1 && nums[j] == nums[j-1]) continue;

            int k = j+1; 
            int l =  n-1; 

            while(k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if(sum == target) {
                    vector<int>temp = {nums[i], nums[j], nums[k], nums[l]};
                    sort(temp.begin(), temp.end());
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;

                }else if(sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}