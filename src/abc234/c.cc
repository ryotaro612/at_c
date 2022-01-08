#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long double ld;
typedef long long ll;

string solve(ll k) {
    string res;

    while(k) {
        if(k & 1) {
            res.push_back('2');
        } else {
            res.push_back('0');
        }
        k >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    ll k;
    cin >> k;
    cout << solve(k) << endl;
    return 0;
}
#endif

// 220022020000202020002022022000002020002222002200002022002200
// 110011010000101010001011011000001010001111001100001011001100