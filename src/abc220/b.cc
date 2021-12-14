#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int k, string a, string b ) {
	ll ad = strtoll(a.c_str(), nullptr, k);
	ll bd = strtoll(b.c_str(), nullptr, k);
	return ad * bd;
}

#ifdef ONLINE_JUDGE
int main() {
	int k;
	cin >> k;
	string a, b;	
	cin >> a >> b;
	cout << solve(k, a, b) << endl;
}
#endif