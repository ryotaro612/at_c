#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll calc(vector<ll> c, ll plus) {
    ll res = 0ll;
    for(ll i = 1ll; i <= 9ll; i++) {
        ll temp = c[i - 1ll];
        if(i - 1ll == plus) {
            temp++;
        }
        res += i * pow(10ll, temp);
    }
    return res;
}

long double solve(ll k, string s, string t) {
    vector<ll> cards(9, k);
    vector<ll> taka_cards(9, 0ll), ao_cards(9, 0ll);
    for(ll i = 0; i < 4ll; i++) {
        cards[s[i] - '1']--;
        cards[t[i] - '1']--;
        taka_cards[s[i] - '1']++;
        ao_cards[t[i] - '1']++;
    }
    long double res = 0;
    ll denom = (9ll * k - 8ll) * (9ll * k - 9ll);
    for(ll taka = 0ll; taka < 9ll; taka++) {
        for(ll ao = 0ll; ao < 9ll; ao++) {
            if(calc(taka_cards, taka) <= calc(ao_cards, ao)) {
                continue;
            }
            ll num;
            if(taka == ao) {
                if(cards[taka] < 2ll)
                    continue;
                num = (cards[taka] * (cards[taka] - 1ll));
            } else { // taka != ao
                if(cards[taka] < 1ll || cards[ao] < 1ll) {
                    continue;
                }
                num = cards[taka] * cards[ao];
            }
            res += (double)num / (double)denom;
        }
    }
    return res;
}

#ifndef _debug
int main() {
    ll k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    cout << fixed << setprecision(12) << solve(k, s, t) << endl;
    return 0;
}
#endif