#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    map<ll, ll> count;
    for(int i = 0; i < n; i++)
        count[a[i]]++;

    vector<ll> cands;
    for(auto p : count)
        if(p.second >= 2)
            cands.push_back(p.first);
    if((int)cands.size() < 2) {
        cout << 0 << endl;
        return 0;
    }
    sort(cands.begin(), cands.end(), greater<ll>());
    if(count[cands[0]] >= 4)
        cout << cands[0] * cands[0] << endl;
    else
        cout << cands[0] * cands[1] << endl;
    return 0;
}
#endif