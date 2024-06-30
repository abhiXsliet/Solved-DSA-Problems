// https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1



//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;
import java.lang.*;

class GFG{
    static class FastReader{ 
		BufferedReader br; 
		StringTokenizer st; 
  
		public FastReader(){ 
			br = new BufferedReader(new InputStreamReader(System.in)); 
		} 
  
		String next(){ 
			while (st == null || !st.hasMoreElements()){ 
				try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); } 
			} 
			return st.nextToken(); 
		} 
  
		String nextLine(){ 
			String str = ""; 
			try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); } 
			return str; 
		} 
		
		int nextInt(){
		    return Integer.parseInt(next());
		}
	}
	
    public static void main(String args[])throws IOException
    {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i = 0;i < n;i++)
                arr[i] = sc.nextInt();
            int q = sc.nextInt();
            int queries[] = new int[2*q];
            for(int i = 0;i < 2*q;i++)
                queries[i] = sc.nextInt();
            
            Solution ob = new Solution();
            List<Integer> ans = new ArrayList<Integer>();
            ans = ob.querySum(n, arr, q, queries);
            StringBuilder out = new StringBuilder();
            for(int i = 0;i < ans.size();i++)
                out.append(ans.get(i) + " ");
            System.out.println(out);
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution{
    // TC : O(N) + O(Q*log(N)) Where Q = No. of Queries & N = Size of Array
    // SC : O(N)
    List<Integer> querySum(int n, int arr[], int q, int queries[])
    {
        int[] segTree = new int[4 * n];
        
        buildTree(0, 0, n - 1, arr, segTree);
        
        List<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < 2*q; i += 2) {
            int startQ = queries[i] - 1;
            int endQ   = queries[i + 1] - 1;
            result.add(Query(0, 0, n - 1, startQ, endQ, segTree));
        }
        
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    private static void buildTree(int i, int l, int r, int arr[], int[] segTree) {
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }
        
        int mid = (l + r) >> 1;
        buildTree(2*i + 1, l, mid, arr, segTree);
        buildTree(2*i + 2, mid + 1, r, arr, segTree);
        
        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }
    
    // TC : O(log(N))
    // SC : O(1)
    private static int Query(int i, int l, int r, int startQ, int endQ, int[] segTree) {
        if (l > endQ || r < startQ) // out of bound
            return 0;
        if (l >= startQ && r <= endQ) // completely overlap
            return segTree[i];
        
        int mid = l + (r - l) / 2;
        return (Query(2*i + 1, l, mid, startQ, endQ, segTree) + 
                Query(2*i + 2, mid + 1, r, startQ, endQ, segTree));
    }
}