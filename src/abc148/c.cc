#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

#ifdef ONLINE_JUDGE
int main() {
    ll a, b;
    cin >> a >> b;
    cout << lcm(max(a, b), min(a, b)) << endl;
}
#endif