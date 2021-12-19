#include <bits/stdc++.h>
using namespace std;

double solve(int t, int x) { return (double)t / (double)x; }

#ifdef ONLINE_JUDGE
int main() {
    int t, x;
    cin >> t >> x;
    cout << fixed << setprecision(12) << solve(t, x) << endl;
    return 0;
}
#endif