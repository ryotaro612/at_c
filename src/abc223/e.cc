#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll calc_edge(ll y, ll area) {
    if(area % y == 0ll)
        return area / y;
    return area / y + 1ll;
}

bool vertical3(ll x, ll y, ll a, ll b, ll c) {
    ll edge_a = calc_edge(y, a);
    ll edge_b = calc_edge(y, b);
    ll edge_c = calc_edge(y, c);
    return edge_a + edge_b + edge_c <= x;
}

bool vert1hori2(ll x, ll y, ll a, ll b, ll c) {
    ll edge_a = calc_edge(y, a);
    ll remain_x = x - edge_a;
    if(remain_x <= 0)
        return false;
    ll edge_b = calc_edge(remain_x, b);
    ll edge_c = calc_edge(remain_x, c);
    // cout << "remain_x " << remain_x << " edge_b " << edge_b << " " << edge_c
    // << endl;
    return edge_b + edge_c <= y;
}

bool solve(ll x, ll y, ll a, ll b, ll c) {
    if(vertical3(x, y, a, b, c) || vertical3(y, x, a, b, c))
        return true;
    vector<ll> areas = {a, b, c};
    sort(areas.begin(), areas.end());
    do {
        // cout << areas[0] << " " << areas[1] << " "  << areas[2] << endl;
        if(vert1hori2(x, y, areas[0], areas[1], areas[2]) ||
           vert1hori2(y, x, areas[0], areas[1], areas[2]))
            return true;
    } while(next_permutation(areas.begin(), areas.end()));

    return false;
}
#ifdef ONLINE_JUDGE
int main() {
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    if(solve(x, y, a, b, c))
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
    return 0;
}
#endif