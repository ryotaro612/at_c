#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;

int solve(int x) {
    if(x % 100 == 0)
        return 100;
    return 100 - (x - (x / 100) * 100);
}

#ifdef ONLINE_JUDGE
int main() {
    int x;
    cin >> x;
    cout << solve(x) << endl;
}
#endif