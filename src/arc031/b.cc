#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

void uni(int x, int y, set<pair<int, int>> &count, vector<string> &area) {
    if(area[x][y] == 'o') {
        count.insert(make_pair(x, y));
        // cout << "uni -> " << x << " " << y << endl;

        if(x > 0 && count.find(make_pair(x - 1, y)) == count.end())
            uni(x - 1, y, count, area);
        if(x < 9 && count.find(make_pair(x + 1, y)) == count.end())
            uni(x + 1, y, count, area);
        if(y > 0 && count.find(make_pair(x, y - 1)) == count.end())
            uni(x, y - 1, count, area);
        if(y < 9 && count.find(make_pair(x, y + 1)) == count.end())
            uni(x, y + 1, count, area);
    }
}

pair<int, int> find_start(vector<string> &area) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(area[i][j] == 'o')
                return make_pair(i, j);
        }
    }
    // unreachable
    return make_pair(-1, -1);
}

string solve(vector<string> &area) {
    int circles = 0;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(area[i][j] == 'o')
                circles++;
    pair<int, int> start = find_start(area);
    // cout << circles << " circles " << start.first << " " << start.second <<
    // endl;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            char temp = area[i][j];
            area[i][j] = 'o';
            set<pair<int, int>> cs;
            uni(start.first, start.second, cs, area);
            // cout << i << " " << j << " -> " << cs.size() << endl;
            if(temp == 'x' && (int)cs.size() == circles + 1)
                return "YES";
            if(temp == 'o' && (int)cs.size() == circles)
                return "YES";

            area[i][j] = temp;
        }
    }
    return "NO";
}

#ifndef _debug
int main() {
    vector<string> area(10);
    for(int i = 0; i < 10; i++)
        cin >> area[i];
    cout << solve(area) << endl;
}
#endif