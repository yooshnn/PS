#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Tree {
public:
    int N; // 정점의 수
    int root{ -1 }; // 루트
    vector<int> depth;
    vector<int> parent; // 각 정점의 부모
    vector<vector<int>> children; // 각 정점의 자식
    vector<vector<int>> edge; // 간선 정보

    // 생성자
    Tree() : N(0) {}
    Tree(int n) : N(n + 1) { parent.resize(N, -1); children.resize(N); edge.resize(N); depth.resize(N, -1); }

    // 트리 빌드
    void build(int node) {
        if (root == -1) root = node; // 최초 루트 저장
        for (int i = 0; i < edge[node].size(); ++i) {
            if (parent[edge[node][i]] == -1) {
                if (edge[node][i] == root) continue;
                parent[edge[node][i]] = node;
                children[node].push_back(edge[node][i]);
                build(edge[node][i]);
            }
        }
    }

    // 간선추가
    void add_edge(int u, int v) {
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    // 각 노드의 하위 최대 깊이
    int dfs(int node) {
        if (children[node].size() == 0) {
            depth[node] = 0;
            return 0;
        }
        int r = 0;
        for (int next : children[node]) {
            r = max(r, dfs(next) + 1);
        }
        depth[node] = r;
        return depth[node];
    }
};

int N, S, D;
int u, v;
int res = 0;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> N >> S >> D;
    Tree tree(N);
    for (int i = 1; i < N; ++i) {
        cin >> u >> v;
        tree.add_edge(u, v);
    }
    tree.build(S);

    tree.dfs(S);
    for (int i = 1; i <= N; ++i) {
        //cout << i << " : " << tree.parent[i] << endl;
        //cout << i << " : " << tree.depth[i] << "\n";
        if (tree.depth[i] >= D) {
            res++;
        }
    }
    cout << max(0, (res - 1) * 2);

    return 0;
}