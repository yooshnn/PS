#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
inline int input() { int num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

int N, R, Q;
vector<int> graph[100001];

vector<int> child[100001];
int par[100001];
int res[100001];

void build(int r) {
    for (int i : graph[r]) {
        if (i != R && par[i] == 0) {
            par[i] = r;
            child[r].push_back(i);
            build(i);
        }
    }
}

int solve(int id) {
    int req = 1;
    for (int& i : child[id]) {
        req += solve(i);
    }
    return res[id] = req;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    N = input(), R = input(), Q = input();
    for (int i = 0; i < N - 1; ++i) {
        int u, v; u = input(), v = input();
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    build(R);
    solve(R);

    for (int i = 0; i < Q; ++i) {
        int u; u = input();
        cout << res[u] << "\n";
    }
}