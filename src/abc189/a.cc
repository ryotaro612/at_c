#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string c) {
    return (c[0] == c[1] && c[0] == c[2]) ? "Won" : "Lost";
}
/*
int main() {
    string c;
    cin >> c;
    cout << solve(c) << endl;
}
*/