#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp() {}

#ifndef _LOCAL
int main() {
    vector<int> b(10);
    for(int i = 0; i < 10; i++)
        cin >> b[i];
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> inv_b(10);
    for(int i = 0; i < 10; i++)
        inv_b[b[i]] = i;

    sort(a.begin(), a.end(), [&](const string s1, const string s2) -> bool {
        ll n1 = 0ll, n2 = 0ll;
        for(auto c : s1) {
            n1 *= 10ll;
            n1 += inv_b[c - '0'];
        }
        for(auto c : s2) {
            n2 *= 10ll;
            n2 += inv_b[c - '0'];
        }
        return n1 < n2;
    });
    for(auto aa : a)
        cout << aa << endl;
    return 0;
}
#endif