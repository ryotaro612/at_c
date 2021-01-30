#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int a, int b, int c) {
    if(c == 0) {
        while(true) {
            if(a <= 0) {
                return "Aoki";
            }
            a--;
            if(b <= 0) {
                return "Takahashi";
            }
            b--;
        }
    }
    while(true) {
        if(b <= 0) {
            return "Takahashi";
        }
        b--;
        if(a <= 0) {
            return "Aoki";
        }
        a--;
    }
}
/*
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
}
*/