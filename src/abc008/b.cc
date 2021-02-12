#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int n, vector<string> s) {
    map<string, int> a;
    for(int i = 0; i < (int)n; i++) {
        a[s[i]] += 1;
    }
    string res = "";
    int  count = -1;
    for(auto aa: a) {
        if(aa.second > count) {
            res = aa.first;
            count = aa.second;
        }
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
    cout << solve(n, s) << endl;
}
*/