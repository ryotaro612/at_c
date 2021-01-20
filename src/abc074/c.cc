#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> solve(int a, int b, int c, int d, int e, int f) {
    pair<int, int> res = make_pair(0, 0);
    double density = 0.0;
    for(int aa = 0; aa <= 30; aa++) {
        for(int bb = 0; bb <= 30; bb++) {
            for(int cc = 0; cc <= 30; cc++) {
                for(int dd = 0; dd <= 30; dd++) {
                    int water = 100 * aa + 100 * bb;
                    int suger = cc + dd;
                    if(water + suger > f || water == 0) {
                        continue;
                    }
                    if(suger > (water / 100) * e) {
                        continue;
                    }
                    double current = (double) suger / (double) (suger + water);
                    if(current > density) {
                        // update
                        density = current;
                        cout << "=======" << endl;
                        cout << aa << " water: " << water << " suger: " << suger
                             << endl;
                        cout << "=======" << endl;
                        res = make_pair(water + suger, suger);
                    }
                }
            }
        }
    }
    return res;
}
/*
int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << solve(a, b, c, d, e, f);
}
*/