// https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1




//{ Driver Code Starts
// Initial Template for C
#include <stdio.h>
// } Driver Code Ends
// User function Template for C

void rotate(int n, int mat[][n]) {
     
    // transposing a matrix
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    
    // reversing the elements of a row
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[i][n-1-j];
            mat[i][n-1-j] = temp;
        }
    }
}


//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        }
        rotate(n, a);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }

        printf("~%s", "\n");
    }
    return 0;
}
// } Driver Code Ends