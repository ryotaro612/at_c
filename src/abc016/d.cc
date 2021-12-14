#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll ax, ay, bx, by;
int n;
vector<ll> x, y;
vector<int> done;

bool judge(long x1, long y1, long x2, long y2, long ox1, long oy1, long ox2,
           long oy2) {
    long s;

    if(((x1 - x2) * (oy1 - y1) + (y1 - y2) * (x1 - ox1)) *
           ((x1 - x2) * (oy2 - y1) + (y1 - y2) * (x1 - ox2)) <
       0) {
        if(((ox1 - ox2) * (y1 - oy1) + (oy1 - oy2) * (ox1 - x1)) *
               ((ox1 - ox2) * (y2 - oy1) + (oy1 - oy2) * (ox1 - x2)) <
           0) {
            return true;
        }
    }
    return false;
}

ld calc_area(ll ax, ll ay, ll bx, ll by, ll x, ll y) {
    ld a1 = x - ax, b1 = bx - ax, a2 = y - ay, b2 = by - ay;

    return (ld)0.5 * (ld)(a1 * b2 - b1 * a2);
}

bool calc_side(ll x1, ll y1, ll x2, ll y2) {

    if(calc_area(ax, ay, bx, by, x1, y1) * calc_area(ax, ay, bx, by, x2, y2) <
       0) {
        if(calc_area(x1, y1, x2, y2, ax, ay) *
               calc_area(x1, y1, x2, y2, bx, by) <
           0) {

            return true;
        }
    }
    return false;
}

void solve() {
    cin >> ax >> ay >> bx >> by >> n;
    x.resize(n);
    y.resize(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    int count = 0;
    for(int i = 0; i < n; i++) {
        int next;
        if(i != n - 1)
            next = i + 1;
        else
            next = 0;
        if(calc_side(x[i], y[i], x[next], y[next])) {
            count++;
        }
        /*
    if(judge(ax, ay, bx, by, x[i], y[i], x[next], y[next])) {
        count++;
    }
    */
    }
    cout << count / 2 + 1 << endl;
}

#ifdef ONLINE_JUDGE
int main() {
    solve();
    return 0;
}
#endif
