#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int calc(int time, int c, int s, int f) {
    if(time < s) {
        return s + c;
    }
    if(time % f == 0)
        return time + c;
    return time / f * f + f + c;
}

vector<int> solve(int n, vector<int> c, vector<int> s, vector<int> f) {
    vector<int> res(n, 0);
    for(int i = 0; i < n - 1; i++) {
        //cout << "i: " << i << endl;
        int time = 0;
        for(int j = i; j < n - 1; j++) {
            //cout << "depart: " << j << " time: " << time;
            time = calc(time, c[j], s[j], f[j]);
            //cout << " arrive time " << time << endl;
        }
        res[i] = time;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }
    vector<int> res = solve(n, c, s, f);
    for(int i = 0; i < n; i++)
        cout << res[i] << endl;
    return 0;
}
#endif