#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
    int N; // 노드의 수
    int root{ -1 }; // 루트
    vector<int> res;
    vector<vector<int>> children;

    // 생성자
    Tree() : N(0) {}
    Tree(int n) : N(n + 1) { res.resize(N, 0); children.resize(N); }

    // 간선추가
    void add_children(int u, int v) {
        children[u].push_back(v);
    }

    void dfs(int node, int strength) {
        res[node] += strength;
        for (int next : children[node]) {
            dfs(next, res[node]);
        }
    }
};

int N, M;
int u, v;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> N >> M;
    Tree tree(N);
    for (int i = 1; i <= N; ++i) {
        cin >> u;
        if (u == -1) continue;
        tree.add_children(u, i);
    }

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        tree.res[a] += b;
    }

    tree.dfs(1, 0);

    for (int i = 1; i <= N; ++i) {
        cout << tree.res[i] << " ";
    }


    return 0;
}