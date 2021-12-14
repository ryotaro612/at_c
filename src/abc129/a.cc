#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int p, q, r;
    cin >> p >> q >> r;
    cout << min(p + q, min(q + r, p + r)) << endl;
    return 0;
}
#endif