#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ld pow_kai(ld a, int n) { // aのn乗を計算します。
    ld x = 1;
    while(n > 0) {  //全てのbitが捨てられるまで。
        if(n & 1) { // 1番右のbitが1のとき。
            x = x * a;
        }
        a = a * a;
        n >>= 1; // bit全体を右に1つシフトして一番右を捨てる。
    }
    return x;
}

#ifndef _debug
int main() {
    ld n, m;
    cin >> n >> m;
    ld ans = 1, temp = 1, mini = pow_kai(0.5, m);
    for(int i = 0; temp > 0.00001; i++) {
        temp = ((n - m) * (ld)100 + m * (ld)1900) * ((ld)(i + 1)) *
               pow_kai(1 - mini, i) * mini;
        ans += temp;
        //cout << temp << endl;
    }
    cout << (ll)ans << endl;
    return 0;
}
#endif