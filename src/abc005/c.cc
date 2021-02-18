#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int t, int n, vector<int> a, int m, vector<int> b) {
    vector<bool> used(n, false);
    for(int i = 0; i < m; i++) {
        bool consumed = false;
        //cout << "check: " << i << endl;
        for(int j = 0; j < n; j++) {
            if(b[i] >= a[j] && b[i] <= a[j] + t && !used[j]) {
                //cout << "use_a: " << j << " for_b " << j << endl;
                used[j] = true;
                consumed = true;
                break;
            }
        }
        if(!consumed)
            return "no";
    }
    return "yes";
}
/*
int main() {
    int t, n, m;
    cin >> t >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++)
        cin >> b[i];

    cout << solve(t, n, a, m, b) << endl;
}
*/