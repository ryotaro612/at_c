#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
    前処理: O(MAX_N*MAX_N)
    nCk(n,k): nCk の計算。O(1)
*/
const int MAX_N = 62;          // n の最大値
vector<vector<long long>> com; // 前計算の結果を保存
// 動的計画法で前処理
void init() {
    com.assign(MAX_N, vector<long long>(MAX_N));
    com[0][0] = 1;
    for(int i = 1; i < MAX_N; ++i) {
        com[i][0] = 1;
        for(int j = 1; j < MAX_N; j++) {
            com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]);
        }
    }
}
// nCk を取得
long long nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return com[n][k];
}

ll fact(ll n, ll i) {
    __int128_t ans = 1ll;
    for(ll j = 0; j < i; j++) {
        ans *= n;
        n--;
    }
    return ans;
}

ll calc_pattern(ll a, ll b) {
    ll ans = 1ll;
    ll ab = a + b;
    ll m = min(a, b);
    return fact(ab, m) / fact(m, m);
}

#ifdef ONLINE_JUDGE
int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    string ans = "";
    ll offset = 0ll;
    init();
    while(true) {
        if(a == 0ll && b == 0ll) {
            break;
        }
        if(a > 0) {
            if(b > 0) {
                // aを選ぶ場合の総数
                ll pattern_a = nCk(b + a - 1, b);
                // cout << "pattern_a: " << pattern_a << " " << a - 1 << " " <<
                // b << endl;
                if(k <= pattern_a + offset) {
                    ans.push_back('a');
                    a--;
                    continue;
                } else {
                    offset += pattern_a;
                    b--;
                    ans.push_back('b');
                    continue;
                }
            } else { // a > 0 && b ==0
                ans.push_back('a');
                a--;
                continue;
            }
        } else {
            ans.push_back('b');
            b--;
            continue;
        }
    }

    cout << ans << endl;
    return 0;
}
#endif