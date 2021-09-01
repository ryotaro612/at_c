#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int calc_min(int a, int b, int w) {
    int c = w / a;
    int d = w % a;

    if(d == 0)
        return c;
    //cout << c << endl;
    //cout << d << endl;
    if((double)b >= ((double)d / c) + (double)a)
        return c;
    return -1;
}

int calc_max(int a, int b, int w) {
    int c = w / b;
    int d = w % b;
    if(d == 0)
        return c;
    if((double)b - ((double)(b - d)) / (double)c >= (double)a)
        return c + 1;
    return -1;
}

pair<int, int> solve(int a, int b, int w) {
    return make_pair(calc_max(a, b, w * 1000), calc_min(a, b, w * 1000));
}

#ifndef _debug
int main() {
    int a, b, w;
    cin >> a >> b >> w;
    pair<int, int> res = solve(a, b, w);
    if(res.first == -1) {
        cout << "UNSATISFIABLE" << endl;
    } else {
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
#endif