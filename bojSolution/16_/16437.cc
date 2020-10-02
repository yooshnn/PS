#include <iostream>
#include <algorithm>
#include <vector>
#define pci pair<char,long long>
using namespace std;

class Tree {
public:
    int N; // 정점의 수
    int root{ -1 }; // 루트
    vector<int> parent; // 각 정점의 부모
    vector<vector<int>> children; // 각 정점의 부모
    vector<vector<int>> edge; // 간선 정보
    vector<pci> island; // { 동물, 수 }

    // 생성자
    Tree() : N(0) {}
    Tree(int n) : N(n + 1) { parent.resize(N, -1); children.resize(N); edge.resize(N); island.resize(N); }

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
    void add_edge(char animal, int i, int u, int count) {
        edge[i].push_back(u);
        edge[u].push_back(i);
        island[i] = { animal, count };
    }

    // get
    long long int get_sheep(int node) {
        pci cur = island[node];
        long long ret = 0, sheepT = 0;
        if (cur.first == 'S') sheepT = island[node].second;

        for (int next : children[node]) {
            sheepT += get_sheep(next);
        }
        if (node == 1) return sheepT;

        if (cur.first == 'S') return sheepT;
        else {
            if (sheepT - cur.second <= 0) return 0;
            else return sheepT - cur.second;
        }
    }
};

int N;
int u, c;
char animal;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> N;
    Tree tree(N);
    for (int i = 2; i <= N; ++i) {
        cin >> animal >> c >> u;
        tree.add_edge(animal, i, u, c); // i번 섬과 u번 섬이 연결되어 있다
    }
    tree.build(1);

    cout << tree.get_sheep(1);

    return 0;
}