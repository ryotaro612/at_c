#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    string res = "No";
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++)
            if(n == i * j)
                res = "Yes";
    }
    cout << res << endl;
    return 0;
}
#endif