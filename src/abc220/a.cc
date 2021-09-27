#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c) {
	for(int i = c;i<=b;i+= c) {
		if(i >= a && i<= b) {
			return i;
		}
	}
	return -1;
}

#ifndef _debug
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << solve(a, b, c) << endl;
}
#endif