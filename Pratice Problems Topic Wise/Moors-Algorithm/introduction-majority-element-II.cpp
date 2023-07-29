#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

//TC = O(N)
//SC = O(2)
vector<int> getMajorityII_Brute(vector<int>& arr) {
    vector<int>list;
    for(int i = 0; i < arr.size(); i++) {
        if(list.empty() || list[0] != arr[i]) {
            int cnt = 0;
            for(int j = 0; j < arr.size(); j++) {
                if(arr[i] == arr[j]) cnt++;
            }
            if(cnt > (arr.size()/3)) list.push_back(arr[i]);
        }

        if(list.size() == 2) break;
    }
    return list;
}

//TC => O(N * log(N))
//SC => O(N)
vector<int> getMajorityII_Better(vector<int>& arr) {
    vector<int>list;
    map<int, int>mpp;
    int n = arr.size()/3 + 1;
    for(int i = 0; i < arr.size(); i++) {
        mpp[arr[i]]++;

        if(mpp[arr[i]] == n) list.push_back(arr[i]);
    }
    return list;
}

//TC => O(N)
//SC => O(1)
vector<int> getMajorityII_Optimal(vector<int>& arr) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    vector<int>list;
    for(int i = 0; i < arr.size(); i++) {
        if(cnt1 == 0 && el2 != arr[i]) {
            cnt1++;
            el1 = arr[i];

        } else if(cnt2 == 0 && el1 != arr[i]) {
            cnt2++;
            el2 = arr[i];

        } 
        else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else {
            cnt1--; cnt2--;
        }
    }

    int count1 = 0, count2 = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(el1 == arr[i]) count1++;
        if(el2 == arr[i]) count2++;
    }

    int mini = (int)(arr.size()/3) + 1;

    if(cnt1 >= mini) list.push_back(el1);
    if(cnt2 >= mini) list.push_back(el2);
    
    return list;
}

int main() {
    vector<int> arr = {1, 2};
    cout << "\nMajority element is : " ;
    for(auto& i:getMajorityII_Brute(arr)) 
        cout << i << " ";

    cout << "\nMajority element is : " ;
    for(auto& i:getMajorityII_Better(arr))
        cout << i << " ";

    cout << "\nMajority element is : " ;
    for(auto& i:getMajorityII_Optimal(arr))
        cout << i << " ";


    cout << endl;
    return 0;
}