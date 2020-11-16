#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s, int x, int y) {
    vector<int> s_x, s_y;
    s_x.push_back(0);
    s_y.push_back(0);
    bool mode_x = true;
    for(auto c : s) {
        if(c == 'T') {
            if(mode_x) {
                s_y.push_back(0);
            } else {
                s_x.push_back(0);
            }
            mode_x = !mode_x;
            continue;
        }
        if(mode_x) {
            s_x[s_x.size() - 1] += 1;
        } else {
            s_y[s_y.size() - 1] += 1;
        }
    }
    set<int> xs{s_x[0]};
    for(int i = 1; i < (int)s_x.size(); i++) {
        set<int> temp;
        for(auto prev : xs) {
            temp.insert(prev + s_x[i]);
            temp.insert(prev - s_x[i]);
        }
        xs = temp;
    }

    if(xs.find(x) == xs.end()) {
        return "No";
    }
    set<int> ys{0};
    for(auto ss : s_y) {
        set<int> temp;
        for(auto prev : ys) {
            temp.insert(prev + ss);
            temp.insert(prev - ss);
        }
        ys = temp;
    }
    if(ys.find(y) == ys.end()) {
        return "No";
    }

    return "Yes";
}
/*
int main() {
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    cout << solve(s, x, y);
}
*/