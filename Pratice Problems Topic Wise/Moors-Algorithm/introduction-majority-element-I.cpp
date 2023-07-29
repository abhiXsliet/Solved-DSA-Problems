#include<iostream>
#include<vector>
#include<map>
using namespace std;

//TC => O(N^2)
//SC => O(1)
int findMajority_Brute(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        int cnt = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[i] == arr[j]) cnt++;
        }

        if(cnt > arr.size()/2) {
            cout << "\nMajority element is : " << arr[i] << endl;
            return cnt;
        }
    }
    return -1;
}

//TC => O(Nlog(N))
//SC => O(N)
int findMajority_Better(vector<int>& arr) {
    map<int, int>mpp;
    for(int i = 0; i < arr.size(); i++) {
        mpp[arr[i]]++;
    }

    for(auto& i: mpp) {
        if(i.second > arr.size()/2) {
            cout << "\nMajority element is : " << arr[i.first] << endl;
            return i.second;
        }
    }
    return -1;
}

//TC => O(N)
//SC => O(1)
pair<int, int> findMajority_Moores(vector<int>& arr) {
    int cnt = 0;
    int ele;
    for(int i = 0; i < arr.size(); i++) {
        if(cnt == 0) {
            cnt = 1;
            ele = arr[i];

        } else if(arr[i] == ele) {
            cnt++;
        } else {
            cnt--;
        }
    }
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(ele == arr[i]) count++;
    }
    
    return {count, ele};
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 3, 1, 2, 1, 1, 1};

    cout << "Count of majority element is : " << findMajority_Brute(arr) << endl;
    cout << "Count of majority element is : " << findMajority_Better(arr) << endl;

    int count = findMajority_Moores(arr).first;
    int ele = findMajority_Moores(arr).second;
    if(count > (arr.size()/2)) {
        cout << "\nMajority element (using Moore's Algo) is : " << ele << endl;
    } else {
        cout << "\nNo majority element found" << endl;
    }
    cout << "Count of majority element (using Moore's Algo) is : " << count << endl;


    cout << endl;
    return 0;
}