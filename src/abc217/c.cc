#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];

    rep(i, n) { q[p[i] - 1] = i + 1; }
    rep(i, n) {
        cout << q[i];
        if(i != n - 1)
            cout << " ";
        else
            cout << endl;
    }
}
#endif