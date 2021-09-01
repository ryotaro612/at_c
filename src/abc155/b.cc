#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(int n, vector<int> a) {
    for(auto aa : a)
        if(aa % 2 == 0)
            if(aa % 3 != 0 && aa % 5 != 0)
                return "DENIED";

    return "APPROVED";
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
#endif