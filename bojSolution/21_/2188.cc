#include <bits/stdc++.h>
using namespace std;
const int MAX = 10001;

int N, M, A[MAX], B[MAX];

vector<int> edge[MAX];
bool visited[MAX];

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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int in;
			cin >> in;
			edge[i].push_back(in);
		}
	}
	int match = 0;
	fill(A + 1, A + MAX - 1, -1);
	fill(B + 1, B + MAX - 1, -1);
	for (int i = 1; i <= N; i++) {
		if (A[i] == -1) {
			fill(visited + 1, visited + MAX - 1, 0);
			if (dfs(i)) match++;
		}
	}
	cout << match;
}