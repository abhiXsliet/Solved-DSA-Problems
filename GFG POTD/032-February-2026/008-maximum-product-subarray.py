# https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1/




class Solution:
	def maxProduct(self,arr):
		n = len(arr)
		maxi = mini = res = arr[0]
		
		for i in range(1, n):
		    temp = maxi
		    maxi = max(arr[i], arr[i] * mini, arr[i] * maxi)
		    mini = min(arr[i], arr[i] * mini, arr[i] * temp)
		    res  = max(res, maxi)
		
		return res