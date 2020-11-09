#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string n) {
    int d[3] = {0, 0, 0};
    int num = (int)n.size();
    int sum = 0;
    for(int i = 0; i < num; i++) {
        d[(n[i] - '0') % 3]++;
    }
    int mod = (d[1] + 2 * d[2]) % 3;
    if(mod == 0) {
        return 0;
    }
    if(mod == 1) {
        if(d[1] > 0) {
            return num == 1 ? -1 : 1;
        }
        if(d[2] >= 2) {
            return num <= 2 ? -1 : 2;
        }
        return -1;
    }
    // mod == 2;
    if(d[2] > 0) {
        return num == 1 ? -1 : 1;
    }
    if(d[1] >= 2) {
        return num <= 2 ? -1 : 2;
    }
    return -1;
}
/*
int main() {
    string n;
    cin >> n;
    cout << solve(n);
}
*/