#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> commands(q);
    map<int, set<int>> pos_pigeon;
    map<int, int> pigeon_pos;
    map<int, int> last;
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        commands[i].push_back(type);
        
        if (type == 1 || type == 2) {
            int a, b;
            cin >> a >> b;
            commands[i].push_back(a - 1);
            commands[i].push_back(b - 1);
        } else {
            int a;
            cin >> a;
            commands[i].push_back(a - 1);
            pos_pigeon[a - 1].insert(a - 1);
            pigeon_pos[a - 1] = a - 1;
            last[a - 1] = i;
        }
    }
    
    for (int i = 0; i < q; i++) {
        if (commands[i][0] == 1) {
            int a = commands[i][1];
            int b = commands[i][2];
            if (pigeon_pos.find(a) != pigeon_pos.end()) {
                int pos = pigeon_pos[a];
                pos_pigeon[pos].erase(a);
                pos_pigeon[b].insert(a);
                pigeon_pos[a] = b;
            }
        } else if (commands[i][0] == 2) {
            int a = commands[i][1];
            int b = commands[i][2];
            
            for (int p : pos_pigeon[a]) {
                pigeon_pos[p] = b;
            }
            for (int p : pos_pigeon[b]) {
                pigeon_pos[p] = a;
            }
            
            swap(pos_pigeon[a], pos_pigeon[b]);
        } else {
            int a = commands[i][1];
            cout << pigeon_pos[a] + 1 << "\n";
            if (last[a] == i) {
                pos_pigeon[pigeon_pos[a]].erase(a);
                pigeon_pos.erase(a);
            }
        }
    }
    
    return 0;
}
