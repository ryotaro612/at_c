#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifndef _debug
int main() {
    int q;
    cin >> q;
    vector<int> c(q), x(q, 0);
    rep(i, q) {
        cin >> c[i];
        if(c[i] == 1)
            cin >> x[i];
    }
    deque<int> que;
    multiset<int> sorted;
    rep(i, q) {
        if(c[i] == 1) {
            que.push_back(x[i]);
        } else if(c[i] == 2) {
            if(!sorted.empty()) {
                cout << *sorted.begin() << endl;
                auto iter = sorted.begin();
                iter++;
                sorted.erase(sorted.begin(), iter);
            } else {
                cout << que.front() << endl;
                que.pop_front();
            }
        } else { // c[i] == 3
            while(!que.empty()) {
                sorted.insert(que.front());
                que.pop_front();
            }
        }
    }
    return 0;
}
#endif