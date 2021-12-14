#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int x) {
    int mx = 100010;
    vector<bool> d(mx + 1, true);
    for(int i = 2; i * i <= mx; i++) {
        if(!d[i])
            continue;

        int peek = i * 2;
        while(peek <= mx) {
            d[peek] = false;
            peek += i;
        }
    }
    vector<int> primes;
    for(int i = 0; i < mx; i++)
        if(d[i])
            primes.push_back(i);

    int res = 2;
    for(int i = 0; i < (int)primes.size(); i++)
        if(x <= primes[i])
            return primes[i];

    return -1;
}

#ifdef ONLINE_JUDGE
int main() {
    int x;
    cin >> x;
    cout << solve(x) << endl;
    return 0;
}
#endif
