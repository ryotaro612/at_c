#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n, l;
    cin >> n >> l;
    vector<string> area(l);
    string g;
    getline(cin, g);
    for(int i = 0; i < l; i++) {
        getline(cin, area[i]);
    }
    /*
    for(auto a : area) {
        cout << a << endl;
    }
    */
    string y;
    getline(cin, y);
    int p;
    for(int i = 0; i < n + n - 1; i += 2) {
        if(y[i] == 'o') {
            p = i;
        }
    }
    // cout << "start " << p << endl;
    for(int i = l - 1; i >= 0; i--) {
        // cout << i << "-> " << area[i] << endl;
        if(p != 0 && area[i][p - 1] == '-')
            p -= 2;
        else if(p != n + n - 1 - 1 && area[i][p + 1] == '-')
            p += 2;
        // cout << i << " " << p << endl;
    }
    cout << p / 2 + 1 << endl;
    return 0;
}
#endif