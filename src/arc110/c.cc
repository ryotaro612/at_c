#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> p) {
    for(int i = 0; i < n; i++)
        p[i]--;
    vector<int> res;
    bool change = false;
    while(true) {
        for(int i = 0; i < n - 1;) {
            if(p[i] - i > 0 && p[i + 1] - (i + 1) < 0) {
                res.push_back(i + 1);
                swap(p[i], p[i + 1]);
                change = true;
                if(i > 0)
                    i--;
            } else {
                i++;
            }
        }
        if(!change)
            break;
        change = false;
    }
    if((int)res.size() != n - 1)
        return {-1};
    for(int i = 0; i < n; i++) {
        if(p[i] != i)
            return {-1};
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    vector<int> res = solve(n, p);

    for(auto r : res)
        cout << r << endl;

    return 0;
}
#endif