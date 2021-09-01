#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> l(q), r(q);
    for(int i = 0; i < q; i++)
        cin >> l[i] >> r[i];

    vector<int> sum(n + 1, 0), res(q);
    for(int i = 1; i < n; i++) {
        sum[i + 1] = sum[i];
        if(s[i - 1] == 'A' && s[i] == 'C') {
            sum[i + 1]++;
        }
    }
    for(int i = 0; i < q; i++)
        res[i] = sum[r[i]] - sum[l[i]];
    for(auto r : res)
        cout << r << endl;
    return 0;
}
#endif