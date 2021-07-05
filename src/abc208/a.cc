#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    if(a <= b && b <= 6 * a)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
}

#ifndef _LOCAL
int main() {
    solve();
    return 0;
}
#endif