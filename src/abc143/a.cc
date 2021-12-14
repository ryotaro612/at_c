#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int a, b;
    cin >> a >> b;

    cout << max(a - 2 * b, 0) << endl;
    return 0;
}
#endif