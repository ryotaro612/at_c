#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int sum(int i, vector<int> &bit) {
    int res = 0;
    while(i > 0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

void add(int i, int x, vector<int> &bit) {
    int n = bit.size();
    while(i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

vector<ll> solve(int n, vector<int> &a) {
    vector<int> bit(500000);
    vector<ll> res(n);
    rep(i, n) {
        a[i]++;
        res[0] += i - sum(a[i], bit);
        add(a[i], 1, bit);
    }
    rep(i, n-1) {
        res[i+1]= res[i] - (a[i] - 1) + (n-a[i]);
    }
    return res;
    /*
    N = 4
    a = 0 1 2 3
    b0 = 0 1 2 3
    b1 = 1 2 3 0
    b2 = 2 3 0 1
    b3 = 3 0 1 2
    */
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> res = solve(n, a);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif