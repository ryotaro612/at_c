#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

double solve(int a, int b) { return ((double)(100 * (a - b))) / (double)a; }

#ifdef ONLINE_JUDGE
int main() {
    int a, b;
    cin >> a >> b;
    cout << fixed << setprecision(12) << solve(a, b) << endl;
    return 0;
}
#endif