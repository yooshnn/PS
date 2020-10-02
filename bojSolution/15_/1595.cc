#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define tup tuple<int,int,int>
#define pii pair<int,int>
using namespace std;

class Tree {
public:
    int N; // 정점의 수
    int root{ -1 }; // 루트
    vector<int> parent; // 각 정점의 부모
    vector<vector<pii>> edge; // 간선 정보

    // 생성자
    Tree() : N(0) {}
    Tree(int n) : N(n + 1) { parent.resize(N, -1); edge.resize(N); }

    // 간선추가
    void add_edge(int u, int v, int w) {
        edge[u].push_back({ v, w });
        edge[v].push_back({ u, w });
    }

    // 트리 빌드
    void build(int node) {
        if (root == -1) root = node; // 최초 루트 저장
        for (int i = 0; i < edge[node].size(); ++i) {
            int nodeid = edge[node][i].first;
            if (parent[nodeid] == -1) {
                if (nodeid == root) continue;
                parent[nodeid] = node;
                build(nodeid);
            }
        }
    }

    // get
    pii get_farthest_node(int node, int farthest) {
        pii ret{ -1, farthest };
        queue<pii> Q;
        vector<bool> visited(N, false);
        Q.push({ node, farthest });
        visited[node] = true;
        while (!Q.empty()) {
            pii cur = Q.front();
            Q.pop();
            if (ret.second < cur.second) {
                ret = { cur.first, cur.second };
            }
            for (int i = 0; i < edge[cur.first].size(); ++i) {
                if (visited[edge[cur.first][i].first]) continue;
                visited[edge[cur.first][i].first] = true;
                Q.push({ edge[cur.first][i].first, cur.second + edge[cur.first][i].second });
            }
        }
        return ret;
    }
};

int N = 1;
int u, v, w;
vector<tup> uvw;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    while (cin >> u >> v >> w) {
        uvw.push_back({ u, v, w });
        N++;
    }
    if (N == 1) {
        cout << 0;
        return 0;
    }

    Tree tree(N);
    for (int i = 0; i < N - 1; ++i) {
        tree.add_edge(get<0>(uvw[i]), get<1>(uvw[i]), get<2>(uvw[i]));
    }
    tree.build(1);

    cout << tree.get_farthest_node(tree.get_farthest_node(1, 0).first, 0).second;

    return 0;
}