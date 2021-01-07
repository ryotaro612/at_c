#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sub(string s) { return (s[0] - '0') + (s[1] - '0') + (s[2] - '0'); }

int solve(string a, string b) { return sub(a) >= sub(b) ? sub(a) : sub(b); }
/*
int main() {
    string a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}
*/