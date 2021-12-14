#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    vector<ll> cand(n);
    for(int i = 0; i < n; i++) {
        cand[i] = a[0] ^ b[i];
    }
    set<ll> ans;
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++) {
        vector<ll> temp(n);
        for(int j = 0; j < n; j++) {
            temp[j] = a[j] ^ cand[i];
        }
        sort(temp.begin(), temp.end());
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if(b[j] != temp[j])
                ok = false;
        }
        if(ok)
            ans.insert(cand[i]);
    }
    cout << (int)ans.size() << endl;
    for(auto aa : ans)
        cout << aa << endl;
    return 0;
}
#endif