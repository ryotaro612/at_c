#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<bool> done;
vector<vector<int>> graph;
vector<int> res;
void rec(int index) {
    res.push_back(index + 1);
    done[index] = true;
    for(int i = 0; i < (int)graph[index].size(); i++) {
        if(!done[graph[index][i]]) {
            rec(graph[index][i]);
            res.push_back(index + 1);
        }
    }
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1), b(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    done = vector<bool>(n, false);
    graph = vector<vector<int>>(n);
    for(int i = 0; i < n - 1; i++) {
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }
    for(int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    /*
for(int i = 0; i < graph.size(); i++) {
    for(int j = 0; j < graph[i].size(); j++) {
        cout << graph[i][j] << " ";
    }
    cout << endl;
}
    cout << "=====" << endl;
    */

    rec(0);

    for(int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if(i == (int)res.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}
#endif