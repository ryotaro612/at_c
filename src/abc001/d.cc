#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int to_min(int v) { return v / 100 * 60 + v % 100; }

int to_time(int v) {
    int hour = v / 60;
    return hour * 100 + (v - 60 * hour);
}

pair<int, int> duration_min(string s) {
    int from = to_min(atoi(s.substr(0, 4).c_str()));
    int maru = from % 10;
    if(0 < maru && maru < 5) {
        from -= maru;
    } else if(5 < maru && maru < 10) {
        from -= (maru - 5);
    }

    int to = to_min(atoi(s.substr(5, 9).c_str()));
    int maru2 = to % 10;
    if(0 < maru2 && maru2 < 5) {
        to = to - maru2 + 5;
    } else if(5 < maru2 && maru2 < 10) {
        to = to - maru2 + 10;
    }
    return make_pair(from, to);
}

vector<pair<int, int>> to_mins(vector<string> s) {
    vector<pair<int, int>> mins;
    for(int i = 0; (int)i < (int)s.size(); i++) {
        mins.push_back(duration_min(s[i]));
    }
    return mins;
}

vector<pair<int, int>> to_hours(vector<pair<int, int>> s) {
    vector<pair<int, int>> res;
    for(auto ss : s) {
        res.push_back(make_pair(to_time(ss.first), to_time(ss.second)));
    }
    return res;
}

vector<pair<int, int>> solve(int n, vector<string> s) {
    vector<pair<int, int>> mins = to_mins(s);
    const int day = 60 * 24 + 10;
    vector<int> imos(day, 0);
    for(auto minute_pair : mins) {
        imos[minute_pair.first]++;
        imos[minute_pair.second + 1]--;
    }
    for(int i = 1; i < day; i++) {
        imos[i] += imos[i - 1];
    }
    vector<int> begin, ed;
    for(int i = 0; i < day; i++) {
        if(imos[i] != 0 && (i == 0 || imos[i - 1] == 0)) {
            int time = to_time(i);
            //cout << "Find Start " << time << endl;
            begin.push_back(time);
        }
        if(imos[i] == 0 && i != 0 && imos[i - 1] != 0) {
            int time = to_time(i - 1);
            //cout << "End Start " << time << endl;
            ed.push_back(time);
        }
    }
    vector<pair<int, int>> res;
    for(int i = 0; i < (int)begin.size(); i++) {
        res.push_back(make_pair(begin[i], ed[i]));
    }
    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<pair<int, int>> res = solve(n, s);
    for(auto a : res) {
        cout << std::setfill('0') << std::right << std::setw(4) << a.first;
        cout << "-";
        cout << std::setfill('0') << std::right << std::setw(4) << a.second;
        cout << endl;
    }
}
*/