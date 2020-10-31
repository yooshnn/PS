#include <bits/stdc++.h>
using namespace std;

int root, del, cnt;
vector<int> child[50];

void dfs(int id) {
    if (id == del && id == root) return;
    bool hasChild = false;
    for (int c : child[id]) {
        if (c == del) continue;
        dfs(c);
        hasChild = true;
    }
    if (!hasChild) cnt++;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int p; cin >> p;
        if (p == -1) { root = i; continue; }
        child[p].push_back(i);
    }
    cin >> del;
    dfs(root);
    cout << cnt;
}