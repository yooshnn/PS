#include <bits/stdc++.h>
using namespace std;
const int MAX = 10020;

//A[i], B[i] : 각 정점이 매칭된 반대편 정점 인덱스
int N, M, A[MAX], B[MAX];

vector<int> edge[MAX];
bool visited[MAX];

//A그룹의 정점 a를 매칭시키는 데 성공하면 1 반환
//반대편이 매칭되지 않았으면 매칭시키고,
//이미 매칭되어 있다면 원래 매칭된 정점을 다른 정점과 매칭시킨다.
bool dfs(int a) {
	visited[a] = 1;
	for (int b : edge[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0, p, q; i < M; ++i) {
		cin >> p >> q;
		edge[p].push_back(q);
	}

	int match = 0;
	fill(A + 1, A + MAX - 1, -1);
	fill(B + 1, B + MAX - 1, -1);
	for (int i = 1; i <= N; i++) {
		if (A[i] == -1) {
			fill(visited + 1, visited + MAX - 1, 0);
			if (dfs(i))match++;
		}
	}
	cout << match;
}