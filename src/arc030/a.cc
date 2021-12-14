#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    ll n, k;
    cin >> n >> k;

    ll mx = (n - 3) / 2 + (n - 3) % 2 + 1;

    if(mx >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
#endif