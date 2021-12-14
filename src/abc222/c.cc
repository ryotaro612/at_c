#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

struct Score {
    int index;
    Score(int index) : index(index) {}
};

vector<int> solve(int n, int m, vector<string> &a) {
    vector<pair<int, int>> people(2 * n);
    rep(i, 2 * n) { people[i] = {0, i}; }

    rep(i, m) {
        rep(j, n) {
            char hand = a[people[2 * j].second][i],
                 hand2 = a[people[2 * j + 1].second][i];
            if(hand == 'G') {
                if(hand2 == 'G') {
                } else if(hand2 == 'C') {
                    people[2 * j].first++;
                } else { // hand2 == 'P'
                    people[2 * j + 1].first++;
                }
            } else if(hand == 'C') {
                if(hand2 == 'G') {
                    people[2 * j + 1].first++;
                } else if(hand2 == 'C') {
                } else { // hand2 == 'P'
                    people[2 * j].first++;
                }
            } else { // hand == 'P'
                if(hand2 == 'G') {
                    people[2 * j].first++;
                } else if(hand2 == 'C') {
                    people[2 * j + 1].first++;
                } else { // hand2 == 'P'
                }
            }
        }
        sort(people.begin(), people.end(),
             [](pair<int, int> const &lhs, pair<int, int> const &rhs) {
                 if(lhs.first != rhs.first) {
                     return rhs.first < lhs.first;
                 }
                 return lhs.second < rhs.second;
             });
    }
    vector<int> res(2 * n);
    rep(i, 2 * n) res[i] = people[i].second + 1;
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(2 * n);
    rep(i, 2 * n) cin >> a[i];
    vector<int> res = solve(n, m, a);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif