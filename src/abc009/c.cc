#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int num_diff(string a, string b) {
    int res = 0;
    for(int i = 0; i < (int)a.size(); i++) {
        if(a[i] != b[i])
            res++;
    }
    return res;
}

string dfs(int from, int k, string s, string orig) {
    if(from == (int)s.size() - 1)
        return s;
    int m = from;
    for(int i = (int)s.size() - 1; i >= from + 1; i--) {
        if(s[m] > s[i]) {
            m = i;
        }
    }
    if(m == from) {
        return dfs(from + 1, k, s, orig);
    }
    char temp = s[from];
    s[from] = s[m];
    s[m] = temp;
    int diff = num_diff(orig, s);
    if(diff <= k) {
        return dfs(from + 1, k, s, orig);
    }
    temp = s[from];
    s[from] = s[m];
    s[m] = temp;
    return dfs(from + 1, k, s, orig);
}
string solve(int n, int k, string s) { return dfs(0, k, string(s), s); }
/*
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << solve(n, k, s) << endl;
}
*/