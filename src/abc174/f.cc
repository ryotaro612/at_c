#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

class BinaryIndexTree {
  public:
    /**
     * 最大値がn-1まで対応
     */
    BinaryIndexTree(int n) { bit = vector<int>(n + 1, 0); }

    int sum(int i) {
        i++;
        int res = 0;
        while(i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }

    void add(int i, int v) {
        i++;
        while(i <= (int)bit.size()) {
            bit[i] += v;
            i += i & -i;
        }
    }

  private:
    vector<int> bit;
};

vector<int> solve(int n, int q, vector<int> &c, vector<int> &l,
                  vector<int> &r) {
    BinaryIndexTree bit(n + 1);
    vector<pair<pair<int, int>, int>> rl(q);
    rep(i, q) rl[i] = {{r[i], l[i]}, i};
    sort(rl.begin(), rl.end());
    unordered_map<int, int> color_map;
    int progress = 0;
    vector<int> res(q);
    rep(i, q) {
        int right = rl[i].first.first, left = rl[i].first.second;
        for(int j = progress; j < right; j++) {
            if(color_map.find(c[j]) != color_map.end()) {
                bit.add(color_map[c[j]], -1);
            }
            bit.add(j, 1);
            color_map[c[j]] = j;
            // cout << "j -> " << j << endl;
            // rep(k, 5) cout << bit.sum(k) << " ";
            // cout << endl;
        }
        progress = right;
        // cout << i << endl;
        // rep(k, 5) cout << bit.sum(k) << " ";
        // cout << endl;
        res[rl[i].second] = bit.sum(right - 1) - (left >= 2 ? bit.sum(left-2) : 0);
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n), l(q), r(q);
    rep(i, n) cin >> c[i];
    rep(i, q) cin >> l[i] >> r[i];
    vector<int> res = solve(n, q, c, l, r);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif