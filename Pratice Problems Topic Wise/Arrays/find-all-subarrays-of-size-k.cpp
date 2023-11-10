// printing all the subarrays of size k

#include <iostream> 
using namespace std; 
  
// Function to find the sum of 
// all subarrays of size K 
int print_subArray(int arr[], int n, int k) 
{ 
  
    // Loop to consider every 
    // subarray of size K 
    for (int i = 0; i <= n - k; i++) { 
        
        // print current subarray 
        for (int j = i; j < k + i; j++) 
            cout << arr[j] << " "; 
        cout << endl;
    } 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
  
    // Function Call 
    print_subArray(arr, n, k); 
    cout << endl;
    return 0; 
} 