#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#ifdef ONLINE_JUDGE
int main() {
    ld w, h, x, y;
    cin >> w >> h >> x >> y;
    int count = 0;
    if(x * 2 == w && h == y * 2)
        count = 1;
    cout << fixed << setprecision(12) << h * w / (ld)2 << " " << count << endl;
    return 0;
}
#endif