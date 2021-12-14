#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    string r;
    cin >> r;
    int sum = 0;
    rep(i, r.size()) { sum += max(0, 4 + ('A' - r[i])); }
    cout << fixed << setprecision(12) << (double)sum / (double)r.size();

    return 0;
}
#endif