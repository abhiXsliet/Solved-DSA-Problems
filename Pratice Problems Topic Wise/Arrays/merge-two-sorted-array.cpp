#include<bits/stdc++.h>
using namespace std;

//TC => O(N)
//SC => O(N)
void merge_BruteForce(vector<int>& arr1, vector<int>& arr2) { 
    int n = arr1.size();
    int m = arr2.size();
    int size = n + m;
    long long arr[size];
    int left = 0;
    int right = 0;
    int i = 0;
    while(left < n && right < m) {
        if(arr1[left] <= arr2[right]) arr[i++] = arr1[left++];
        else arr[i++] = arr2[right++];
    }
    while(left < n) {
        arr[i++] = arr1[left++];
    }
    while(right < m) {
        arr[i++] = arr2[right++];
    }
    for(int i = 0; i < size; i++) {
        if(i < n) arr1[i] = arr[i];
        else arr2[i - n] = arr[i];
    }
} 

//TC => O(min(n, m)) + O(nlog(n)) + O(mlog(m)) = O( (n+m)log(n+m) )
//SC => O(1)
void merge_Better(vector<int>& arr1, vector<int>& arr2) { 
    int n = arr1.size();
    int m = arr2.size();
    int left = n-1;
    int right = 0;
    
    while(left >= 0 && right < m) {
        if(arr1[left] > arr2[right]) swap(arr1[left--], arr2[right++]);
        else break;
    } 
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
} 

void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int idx1, int idx2) {
    if(arr1[idx1] > arr2[idx2]) {
        swap(arr1[idx1], arr2[idx2]);
    }
}
// TC => O(log(n)) * O(n+m) = O((n+m) * log(n))
// SC => O(1)
void merge_Optimal(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    while(gap > 0) {
        int left = 0;
        int right = left + gap;
        while(right < len) {
            // comparing arr1 and arr2 elements
            if(left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right-n);
            } 
            // comparing arr2 and arr2 elements
            else if(left >= n) {
                swapIfGreater(arr2, arr2, left-n, right-n);
            } 
            // comparing arr1 and arr1 elements
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {7, 8, 9, 10};

    merge_BruteForce(arr1, arr2);
    for(int i = 0; i <arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    for(int i = 0; i <arr2.size(); i++) {
        cout << arr2[i] << " ";
    }

    cout << endl;

    merge_Better(arr1, arr2);
    for(int i = 0; i <arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    for(int i = 0; i <arr2.size(); i++) {
        cout << arr2[i] << " ";
    }

    cout << endl;

    merge_Optimal(arr1, arr2);
    for(int i = 0; i <arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    for(int i = 0; i <arr2.size(); i++) {
        cout << arr2[i] << " ";
    }

    cout << endl;
    return 0;
}