#include <bits/stdc++.h>
using namespace std;
const int MAX = 200;

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

struct Shark {
	int a, b, c;
	Shark(int A, int B, int C) {
		a = A, b = B, c = C;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<Shark> v;
	for (int i = 1; i <= N; ++i) {
		int a, b, c; cin >> a >> b >> c;
		v.emplace_back(a, b, c);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			if (v[i].a >= v[j].a && v[i].b >= v[j].b && v[i].c >= v[j].c) {
				if (v[i].a == v[j].a && v[i].b == v[j].b && v[i].c == v[j].c) {
					if (j > i) continue;
				}
				edge[i + 1].push_back(j + 1);
				edge[i + N + 1].push_back(j + 1);
			}
		}
	}

	int match = 0;
	fill(A + 1, A + MAX - 1, -1);
	fill(B + 1, B + MAX - 1, -1);
	for (int i = 1; i <= N * 2 + 2; i++) {
		if (A[i] == -1) {
			fill(visited + 1, visited + MAX - 1, 0);
			if (dfs(i)) match++;
		}
	}
	cout << N - match;
}