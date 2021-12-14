#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    ll n, m;
    cin >> n >> m;
    if(n * 2ll >= m) {
        cout << m / 2ll << endl;
        return 0;
    }
    cout << (2ll * n + m) / 4ll << endl;
    return 0;
}
#endif