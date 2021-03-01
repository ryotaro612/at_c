#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const static int MX = 100001;

bool is_mono(vector<int> &v) {
    int siz = (int)v.size();
    for(int i = 1; i < siz; i++) {
        if(v[0] != v[i]) {
            return false;
        }
    }
    return true;
}

int solve(int n, vector<int> v) {
    if(is_mono(v))
        return n / 2;

    map<int, int> mp_0, mp_1;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            mp_0[v[i]]++;
        } else {
            mp_1[v[i]]++;
        }
    }
    priority_queue<pair<int, int>> q_0, q_1;
    for(auto p : mp_0) {
        q_0.push(make_pair(p.second, p.first));
    }
    for(auto p : mp_1) {
        q_1.push(make_pair(p.second, p.first));
    }

    int half = n / 2;
    if(q_0.top().second != q_1.top().second) {
        // cout << "q0 " << q_0.top().first << " - > " << q_1.top().first <<
        // endl;
        return (half - q_0.top().first) + (half - q_1.top().first);
    }
    if(q_0.top().first > q_1.top().first) {
        q_1.pop();
        if(q_1.empty())
            return (half - q_0.top().first) + half;
        return (half - q_0.top().first) + (half - q_1.top().first);
    } else {
        q_0.pop();
        if(q_0.empty())
            return half + (half - q_1.top().first);
        return (half - q_0.top().first) + (half - q_1.top().first);
    }
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << solve(n, v) << endl;
    return 0;
}
#endif