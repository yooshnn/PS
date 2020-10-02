#include <iostream>
#include <set>
using namespace std;

set<int> node;
int u, v, edge = 0;
int Z = 0;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    while (++Z) {
        while (1) {
            cin >> u >> v;
            if (u == v && u == 0) break;
            if (u == v && u == -1) goto esc;
            node.insert(u);
            node.insert(v);
            edge++;
        }
        cout << "Case " << Z << " is " << (((!edge) || (node.size() == edge + 1)) ? "a tree.\n" : "not a tree.\n");
        node.clear();
        edge = 0;
    }
esc:
    return 0;
}