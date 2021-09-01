#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct item {
    int index;
    string ss;
    int pp;
};
vector<int> solve(int n, vector<string> s, vector<int> p) {
    vector<item> res(n);
    for(int i = 0; i < n; i++)
        res[i] = {i + 1, s[i], p[i]};
    auto f = [](item a, item b) { 
        if(a.ss != b.ss)
            return a.ss < b.ss;
        return a.pp > b.pp;
    };
    sort(res.begin(), res.end(), f);
    /*
    for(auto r: res) {
        cout << r.index << " " << r.ss << " " << r.pp << endl;
    }
    */
    
    vector<int> hoge(n);
    for(int i=0;i<n;i++) {
        hoge[i] = res[i].index;
    }
    return hoge;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++)
        cin >> s[i] >> p[i];
    for(auto r : solve(n, s, p))
        cout << r << endl;
    return 0;
}
#endif