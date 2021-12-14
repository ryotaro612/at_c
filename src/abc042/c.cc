#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_ok(int a, set<int> d) {
    while(a != 0) {
        if(d.find(a % 10) != d.end()) {
            return false;
        }
        a /= 10;
    }
    return true;
}

ll solve(int n, int k, vector<int> d) {
    int a = n;
    set<int> dd;
    for(auto ddd : d) {
        dd.insert(ddd);
    }
    while(!is_ok(a, dd)) {
        a++;
    }
    return a;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> d(k);
    for(int i=0;i<k;i++) {
        cin >> d[i];
    }
    cout << solve(n, k, d) << endl;
}
#endif