#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
//#define ll long long
using namespace std;

class Tree {
public:
    int N; // 노드의 수
    vector<pii> nodepair; // 노드 쌍
    vector<vector<int>> edge; // 간선 정보
    vector<bool> visit;

    // 생성자
    Tree() : N(0) {}
    Tree(int n) : N(n + 1) { nodepair.resize(N); edge.resize(N); visit.resize(N, false); }

    // 간선추가
    void add_edge(int u, int v) {
        nodepair.push_back({ u, v });
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    long long nC3(long long x) {
        return (long long)((x * (x - 1) * (x - 2)) / 6);
    }

    // ㄷㄷㄷㅈ
    int solve() {
        long long d = 0, j = 0;
        for (auto np : nodepair) { // 모든 노드 쌍에 대해
            //cout << edge[np.second].size() << endl;
            int temp1 = (edge[np.first].size() - 1), temp2 = (edge[np.second].size() - 1);
            if (temp1 > 0 && temp2 > 0) d += temp1 * temp2;
            //cout << "D: " << d << endl;
            if (!visit[np.first] && edge[np.first].size() >= 3) {
                j += nC3(edge[np.first].size());
                visit[np.first] = true;
            }
            if (!visit[np.second] && edge[np.second].size() >= 3) {
                j += nC3(edge[np.second].size());
                visit[np.second] = true;
            }
        }
        //cout << "d: " << d << ", j: " << j << "\n";
        if (d > 3 * j) {
            return 0;
        }
        else if (d < 3 * j) {
            return 1;
        }
        else {
            return 2;
        }
    }
};

int N;
int u, v;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> N;
    Tree tree(N);
    for (int i = 1; i < N; ++i) {
        cin >> u >> v;
        tree.add_edge(u, v);
    }
    int res = tree.solve();
    if (res == 0) cout << "D";
    else if (res == 1) cout << "G";
    else cout << "DUDUDUNGA";

    return 0;
}