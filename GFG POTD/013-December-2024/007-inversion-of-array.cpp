// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int merge(vector<int>& nums, int start, int mid, int end) {
        int cnt = 0;
        int n1 = mid - start + 1;
        int n2 = end - mid;

        vector<int> left(n1);
        vector<int> right(n2);

        int i = 0, j = 0, k = start;
        while(i < n1) {
            left[i] = nums[k];
            i ++, k ++;
        }
        k = mid + 1;
        while(j < n2) {
            right[j] = nums[k];
            j ++, k ++;
        }

        i = 0, j = 0, k = start;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k] = left[i];
                k ++, i ++;
            } else {
                cnt += (n1 - i);
                nums[k] = right[j];
                k ++, j ++;
            }
        }
        while(i < n1) {
            nums[k] = left[i];
            k ++, i ++;
        }
        while (j < n2) {
            nums[k] = right[j];
            k ++, j ++;
        }
        return cnt;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return 0;
        int mid = low + (high - low) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    } 
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};


//{ Driver Code Starts.
int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends