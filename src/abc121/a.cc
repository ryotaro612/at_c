#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << H * W - h * W - w * H + w * h << endl;
    return 0;
}
#endif