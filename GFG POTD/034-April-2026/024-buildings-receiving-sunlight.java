// https://www.geeksforgeeks.org/problems/buildings-receiving-sunlight3032/1/




class Solution {
    public int visibleBuildings(int arr[]) {
        int n = arr.length;
        int cnt = 1;
        int maxi = arr[0];
        for (int i = 1; i < n; i ++) {
            if (arr[i] >= maxi) {
                maxi = arr[i];
                cnt += 1;
            }
        }
        return cnt;
    }
}