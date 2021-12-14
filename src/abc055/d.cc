#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool fill(int n, string &d, string &s) {
    for(int i = 1; i < n - 2; i++) {
        int prev = (i - 1 + n) % n, next = (i + 1) % n;
        if(s[i] == 'o') {
            if(d[i] == 'S')
                d[next] = d[prev];
            else
                d[next] = (d[prev] == 'W' ? 'S' : 'W');
        } else { // s[i] == 'x'
            if(d[i] == 'S')
                d[next] = (d[prev] == 'W' ? 'S' : 'W');
            else // d[i] == 'W'
                d[next] = d[prev];
        }
    }
    for(int i = n - 2; i < n; i++) {
        int prev = (i - 1 + n) % n, next = (i + 1) % n;
        if(s[i] == 'o') {
            if(d[i] == 'S') {
                if(d[prev] != d[next])
                    return false;
            } else { // d[i] == 'W'
                if(d[prev] == d[next])
                    return false;
            }
        } else { // s[i] == 'x'
            if(d[i] == 'S') {
                if(d[prev] == d[next])
                    return false;
            } else { // d[i] == 'W'
                if(d[prev] != d[next])
                    return false;
            }
        }
    }
    return true;
}

string solve(int n, string s) {
    if(s[0] == 'o') {
        vector<string> cands = {"SSS", "WSW", "WWS", "SWW"};
        for(auto cand : cands) {
            string d(n, ' ');
            d[n - 1] = cand[0];
            d[0] = cand[1];
            d[1] = cand[2];
            if(fill(n, d, s))
                return d;
        }
    } else {
        vector<string> cands = {"WSS", "SSW", "SWS", "WWW"};
        for(auto cand : cands) {
            string d(n, ' ');
            d[n - 1] = cand[0];
            d[0] = cand[1];
            d[1] = cand[2];
            if(fill(n, d, s))
                return d;
        }
    }
    return "-1";
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(n, s) << endl;
}
#endif