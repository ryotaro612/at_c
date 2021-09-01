#include <bits/stdc++.h>
typedef long double ld;
using namespace std;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ld> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    priority_queue<ld, vector<ld>, greater<ld>> que;
    for(int i = 0; i < n; i++) {
        que.push(v[i]);
    }

    while(que.size() > 1) {
        ld temp = que.top();
        que.pop();
        temp = (temp + que.top()) / (ld)2;
        que.pop();
        que.push(temp);
    }
    cout << que.top() << endl;
    return 0;
}
#endif