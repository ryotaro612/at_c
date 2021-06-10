#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {

    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> filters, texts;
    while(getline(ss, s, ' ')) {
        texts.push_back(s);
    }
    int n;
    cin >> n;
    filters.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> filters[i];
    }

    for(int k = 0; k < (int)texts.size(); k++) {
        bool f = false;
        for(auto filter : filters) {
            if(texts[k].size() != filter.size())
                continue;

            bool match = true;
            for(int i = 0; i < (int)texts[k].size(); i++) {
                if(filter[i] == '*')
                    continue;
                if(texts[k][i] != filter[i]) {
                    match = false;
                }
            }
            if(match)
                f = true;
        }
        if(f) {
            for(int i = 0; i < (int)texts[k].size(); i++) {
                cout << '*';
            }
        } else {
            cout << texts[k];
        }
        if(k == (int)texts.size() - 1)
            cout << endl;
        else
            cout << ' ';
    }
    return 0;
}
#endif