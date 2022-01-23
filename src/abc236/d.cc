#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

void rec(vector<pair<int, int>> current, vector<bool> &used,
         vector<vector<pair<int, int>>> &res) {
    bool done = true;
    for(bool e : used) {
        if(!e) {
            done = false;
            break;
        }
    }
    if(done) {
        res.push_back(current);
        return;
    }

    int num_people = used.size();
    int pair_one = 0;
    while(used[pair_one]) {
        pair_one++;
    }
    used[pair_one] = true;
    for(int i = pair_one + 1; i < num_people; i++) {
        if(!used[i]) {
            used[i] = true;
            current.push_back({pair_one, i});
            rec(current, used, res);
            current.pop_back();
            used[i] = false;
        }
    }
    used[pair_one] = false;
}

vector<vector<pair<int, int>>> sub(int num_people) {
    vector<bool> used(num_people, false);
    vector<vector<pair<int, int>>> res;
    rec({}, used, res);
    return res;
}

int solve(int n, vector<vector<int>> am) {
    vector<vector<pair<int, int>>> pairs = sub(2 * n);
    int res = 0;
    for(vector<pair<int, int>> pattern: pairs) {
        int temp = 0;
        for(pair p: pattern) {
            //cout << "(" << p.first << "," << p.second << ") ";
            temp ^= am[p.first][p.second-p.first-1];
        }
        //cout << endl;
        //cout << "tanosisa " << temp << endl;
        res = max(temp, res);
    }
    /*
    for(vector<pair<int, int>> pattern : pairs) {
        for(auto p : pattern) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << endl;
    }
    */
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<vector<int>> am(2 * n - 1);
    rep(i, 2 * n - 1) {
        vector<int> av(2 * n - 1 - i);
        rep(j, av.size()) cin >> av[j];
        am[i] = av;
    }
    cout << solve(n, am) << endl;
    return 0;
}
#endif
