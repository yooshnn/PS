#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Tree {
public:
	int N; // 정점의 수
	vector<int> parent; // 부모 노드
	vector<int> lc, rc; // 자식노드 좌 우

	// 생성자
	Tree() : N(0) {}
	Tree(int n) : N(n) {
		parent.resize(N, -1);
		lc.resize(N, -1);
		rc.resize(N, -1);
	}

	void set_children(int p, int v, int w) {
		if (v != -1) parent[v] = p;
		if (w != -1) parent[w] = p;
		lc[p] = v;
		rc[p] = w;
	}
	void preorder(int root) {
		cout << char(root + 'A' - 1);
		if (lc[root] != -1) preorder(lc[root]);
		if (rc[root] != -1) preorder(rc[root]);
	}
	void inorder(int root) {
		if (lc[root] != -1) inorder(lc[root]);
		cout << char(root + 'A' - 1);
		if (rc[root] != -1) inorder(rc[root]);
	}
	void postorder(int root) {
		if (lc[root] != -1) postorder(lc[root]);
		if (rc[root] != -1) postorder(rc[root]);
		cout << char(root + 'A' - 1);
	}
};

int N;
int u, l, r;

bool visit[27];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N;
	Tree T(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		char c0, c1, c2;
		cin >> c0 >> c1 >> c2;
		u = c0 - 'A' + 1;
		l = (c1 != '.' ? c1 - 'A' + 1 : -1);
		r = (c2 != '.' ? c2 - 'A' + 1 : -1);
		T.set_children(u, l, r);
	}

	T.preorder(1);
	cout << "\n"; 
	T.inorder(1);
	cout << "\n";
	T.postorder(1);

	return 0;
}