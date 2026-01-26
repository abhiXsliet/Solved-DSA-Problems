// https://www.geeksforgeeks.org/problems/generate-permutations-of-an-array/1/




class Solution {
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static void solve(int[] arr, ArrayList<ArrayList<Integer>> result, int idx) {
        if (idx == arr.length) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int num : arr) temp.add(num);
            result.add(temp);
            return;
        }

        for (int i = idx; i < arr.length; i++) {
            swap(arr, i, idx);
            solve(arr, result, idx + 1);
            swap(arr, i, idx); // backtrack
        }
    }

    public static ArrayList<ArrayList<Integer>> permuteDist(int[] arr) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        solve(arr, result, 0);
        return result;
    }
}