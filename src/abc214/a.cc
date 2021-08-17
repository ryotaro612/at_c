#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
	int n;
	cin >> n;
	int ans;
	if(n <= 125)
		ans = 4;
	else if(n <= 211)
		ans = 6;
	else
		ans = 8;

	cout << ans << endl;
	return 0;
}
#endif
