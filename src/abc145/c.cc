#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ld> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    vector<vector<ld>> d(n, vector<ld>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ld x2 = x[i] - x[j], y2 = y[i] - y[j];
            d[i][j] = d[j][i] = sqrt(x2 * x2 + y2 * y2);
        }
    }
    vector<int> patterns(n);
    for(int i = 0; i < n; i++)
        patterns[i] = i;

    ld res = 0;
    int count = 0;
    do {
        for(int i = 0; i < n - 1; i++) {
            res += d[patterns[i]][patterns[i + 1]];
        }
        count++;
    } while(next_permutation(patterns.begin(), patterns.end()));

    cout << fixed << setprecision(12) << res / (ld)count << endl;
    return 0;
}
#endif