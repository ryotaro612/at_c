#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int calc_k(int n) {
    for(int i = 2; i < n + 1; i++) {
        if(i * (i - 1) == 2 * n)
            return i;
    }
    return -1;
}

vector<vector<int>> solve(int n) {
    if(n == 1)
        return {{1}, {1}};
    int k = calc_k(n);
    if(k == -1)
        return {};
    vector<vector<int>> res;
    res.push_back({1});
    res.push_back({1});
    int h = 1, i = 2;
    while(!((int)res.size() == k && (int)res[k - 1].size() == k - 1)) {
        if(h == (int)res.size() - 1) {
            res.push_back({i});
            res[0].push_back(i);
            h = 1;
            i++;
        } else {
            res[h].push_back(i);
            res[res.size() - 1].push_back(i);
            h++;
            i++;
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<vector<int>> res = solve(n);
    if(res.size() == 0) {
        cout << "No" << endl;
        return 0;
    } else {
        cout << "Yes" << endl;
    }

    cout << res.size() << endl;
    for(vector<int> row : res) {
        cout << row.size() << " ";
        for(int i = 0; i < row.size(); i++) {
            cout << row[i];
            if(i == row.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}
#endif
