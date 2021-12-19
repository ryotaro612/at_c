#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(int n, int m, vector<int> &a, vector<int> &b, vector<int> &c,
             vector<int> &d) {
    vector<int> encode(n);
    rep(i, n) { encode[i] = i; }
    rep(i, m) {
        a[i]--;
        b[i]--;
        c[i]--;
        d[i]--;
    }
    vector<pair<int, int>> cd(m);
    rep(i, m) { cd[i] = {c[i], d[i]}; }
    sort(cd.begin(), cd.end());
    // rep(i, m) { 
    //     cout << cd[i].first << " " << cd[i].second << endl; 
    // }
    // cout << " --=- " << endl;
    do {

        vector<pair<int, int>> ab(m);
        rep(i, m) { 
            ab[i] = {
                min(encode[a[i]], encode[b[i]]),
                max(encode[a[i]], encode[b[i]])
            };
        }
        sort(ab.begin(), ab.end());

        // if(encode[0] == 2 && encode[1] == 1 && encode[2] == 0 &&
        //    encode[3] == 3) {
        //     rep(j, m) { cout << ab[j].first << " " << ab[j].second << endl; }
        // }
        bool ok = true;
        rep(i, m) {
            if(!(ab[i].first == cd[i].first && ab[i].second == cd[i].second))
                ok = false;
        }
        if(ok)
            return "Yes";
    } while(next_permutation(encode.begin(), encode.end()));

    return "No";
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), c(m), d(m);
    rep(i, m) { cin >> a[i] >> b[i]; }
    rep(i, m) { cin >> c[i] >> d[i]; }
    cout << solve(n, m, a, b, c, d) << endl;
    return 0;
}
#endif