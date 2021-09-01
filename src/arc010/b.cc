#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> conv(vector<string> &nm) {
    vector<int> res((int)nm.size());
    vector<int> offset = {0,   31,  60,  91,  121, 152,
                          182, 213, 244, 274, 305, 335};
    for(int i = 0; i < (int)nm.size(); i++) {
        string day = nm[i];
        int split = day.find("/");
        int month = stoi(day.substr(0, split));
        int d = stoi(day.substr(split + 1, day.size() - split));

        res[i] = offset[month - 1];
        res[i] += d - 1;
    }
    return res;
}

int solve(int n, vector<string> nm) {
    int all = 366;
    vector<bool> dates(all, false);
    for(int i = 0, j = 0; i < all; i++, j = (j + 1) % 7) {
        if(j == 0 || j == 6)
            dates[i] = true;
    }
    vector<int> holidays = conv(nm);
    sort(holidays.begin(), holidays.end());
    for(auto holiday : holidays) {
        if(dates[holiday]) {
            int begin = holiday;
            while(dates[begin] && begin + 1 < all) {
                begin++;
            }
            dates[begin] = true;
        } else {
            dates[holiday] = true;
        }
    }
    int res = 0;
    for(int i = 0; i < all;) {
        if(!dates[i]) {
            i++;
            continue;
        }
        int temp = i;
        while(temp + 1 < all && dates[temp + 1])
            temp++;
        res = max(res, temp - i + 1);
        i = temp + 1;
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<string> nm(n);
    for(int i = 0; i < n; i++)
        cin >> nm[i];
    cout << solve(n, nm) << endl;
    return 0;
}
#endif