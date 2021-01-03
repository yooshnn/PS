#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 6000;
int N, M, K, A[MAX], B[MAX];
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
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int in;
			cin >> in;
			edge[i].push_back(in);
			edge[i + N].push_back(in);
		}
	}
	int match = 0, match2 = 0;
	fill(A + 1, A + MAX - 1, -1);
	fill(B + 1, B + MAX - 1, -1);
	for (int i = 1; i <= N; i++) {
		if (A[i] == -1) {
			fill(visited + 1, visited + MAX - 1, 0);
			if (dfs(i)) match++;
		}
	}
	for (int i = N+1; i <= N*2+2; i++) {
		if (A[i] == -1) {
			fill(visited + 1, visited + MAX - 1, 0);
			if (dfs(i)) match2++;
		}
	}
	cout << match + min(match2, K);

    return_0;
}