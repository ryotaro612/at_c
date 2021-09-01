#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const ll NUM = 10000000000ll;

char get_digit(int index) {
    if(index % 3 == 0 || index % 3 == 1)
        return '1';
    return '0';
}
ll solve(int n, string t) {
    if(t == "1")
        return NUM * 2ll;
    else if(t == "11" || t == "0" || t == "10" || t == "110")
        return NUM;
    else if(t == "01" || t == "011" || t == "101")
        return NUM - 1ll;
    if(n <= 3)
        return 0ll;

    int begin = -1;
    for(int i = 0; i < 3; i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if(get_digit(i + j) != t[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            begin = i;
            break;
        }
    }
    if(begin == -1)
        return 0ll;
    if(n % 3 == 0ll) {
        if(begin == 0)
            return NUM - ((ll)n / 3ll - 1ll);
        return NUM - (ll)n / 3ll;
    }
    if(n % 3 == 1ll)
        return NUM - (((ll)n - 1ll) / 3ll);
    else { // n % 3 == 2ll
        if(begin == 2)
            return NUM - (((ll)n - 2ll) / 3ll) - 1ll;
        return NUM - (((ll)n - 2ll) / 3ll);
    }
}

#ifndef _debug
int main() {
    int n;
    string t;
    cin >> n >> t;
    cout << solve(n, t) << endl;
}
#endif