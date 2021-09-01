#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> rec(int n, string s) {
    if((int)s.size() == n)
        return {s};
    set<char> cs;
    for(auto ss : s) {
        cs.insert(ss);
    }
    vector<string> res;
    for(int i = 0; i <= (int)cs.size(); i++) {
        char c = i + 'a';
        vector<string> tail = rec(n, s + string(1, c));
        res.insert(res.end(), tail.begin(), tail.end());
    }
    return res;
}
vector<string> solve(int n) {
    vector<string> res = rec(n, "");
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<string> res = solve(n);
    for(auto r : res)
        cout << r << endl;
    return 0;
}
#endif
