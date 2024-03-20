// https://www.codingninjas.com/studio/problems/modular-exponentiation_1082146?



#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {
	int res = 1;
	while(n) {
		if (n&1) {// odd
			res = (1LL * (res) * (x) % m) % m;
		}
		x = (1LL * (x) % m * (x) % m) % m;
		n = n >> 1;
	}
	return res;
}