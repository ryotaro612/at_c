#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int h, int w, int k, vector<string> s) {
    int ans = h + w - 2;
    for(int i = 0; i < 1 << (h - 1); i++) {
        int start_h = 0;
        vector<pair<int, int>> div_h;
        for(int j = 0; j < h - 1; j++) {
            if((1 << j) & i) {
                div_h.push_back({start_h, j});
                start_h = j + 1;
            }
        }
        div_h.push_back({start_h, h - 1});
        vector<int> num(div_h.size(), 0);
        int count = (int)div_h.size() - 1;
        for(int a = 0; a < w; a++) {
            while(count < ans) {
                bool ok = true;
                for(int j = 0; j < (int)div_h.size(); j++) {
                    for(int b = div_h[j].first; b <= div_h[j].second; b++) {
                        if(s[b][a] == '1') {
                            num[j]++;
                            if(num[j] > k)
                                ok = false;
                        }
                    }
                }
                if(ok)
                    break;
                else {
                    count++;
                    num = vector<int>(div_h.size(), 0);
                }
            }
        }
        ans = min(count, ans);
    }
    return ans;
}

#ifndef _LOCAL
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for(int i = 0; i < h; i++)
        cin >> s[i];
    cout << solve(h, w, k, s) << endl;
    return 0;
}
#endif