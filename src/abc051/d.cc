#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 100000000000ll;

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for(int i = 0; i < m; i++) {
        d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
    }

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int ans = 0;
	for(int i=0;i<m;i++) {
		if(d[a[i]][b[i]] != c[i])
			ans++;
	}
	cout << ans << endl;
    return 0;
}
#endif