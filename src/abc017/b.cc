#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int peek, string &x) {
    if(peek <= -1)
        return "YES";
    if(x[peek] == 'o' || x[peek] == 'k' || x[peek] == 'u')
        return solve(peek - 1, x);
    if(peek >= 1 && x[peek - 1] == 'c' && x[peek] == 'h')
        return solve(peek - 2, x);
    return "NO";
}

#ifndef _LOCAL
int main() {
    string x;
    cin >> x;
    cout << solve(x.size() - 1, x) << endl;
    return 0;
}
#endif