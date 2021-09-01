#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {

    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++)
        cin >> a[i] >> b[i];

    set<int> sa, sb;
    for(int i = 0; i < m; i++) {
        if(a[i] == 1)
            sa.insert(b[i]);
        else if(b[i] == 1)
            sa.insert(a[i]);
        if(a[i] == n)
            sb.insert(b[i]);
        else if(b[i] == n)
            sb.insert(a[i]);
    }
    set<int> res;

    set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(),
                     inserter(res, res.end()));
    if(res.size() > 0)
        cout << "POSSIBLE";
    else
        cout << "IMPOSSIBLE";
    cout << endl;

    return 0;
}
#endif