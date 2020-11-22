#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int h, int a) {
    if(h % a == 0)
        return h / a;
    return h / a + 1;
}
/*
int main() {
    int h, a;
    cin >> h >> a;
    cout << solve(h, a);
}
*/