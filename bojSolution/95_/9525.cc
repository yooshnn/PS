#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100001;

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

char board[102][102];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int L; cin >> L;
	for (int r = 1; r <= L; ++r) for (int c = 1; c <= L; ++c) cin >> board[r][c];

	map<pii, int> ptor, ptoc;

	// row
	int t = 1;
	for (int r = 1; r <= L; ++r) {
		for (int c = 1; c <= L; ++c) {
			if (board[r][c] == 'X') continue;
			while (board[r][c] != 'X') {
				ptor[{r, c}] = t;
				if (c + 1 <= L && board[r][c + 1] == '.') c += 1;
				else break;
			}
			t += 1;
		}
	}
	// col
	t = 1;
	for (int c = 1; c <= L; ++c) {
		for (int r = 1; r <= L; ++r) {
			if (board[r][c] == 'X') continue;
			while (board[r][c] != 'X') {
				ptoc[{r, c}] = t;
				if (r + 1 <= L && board[r + 1][c] == '.') r += 1;
				else break;
			}
			t += 1;
		}
	}

	/*cout << "hi\n";
	for (auto i : ptor) cout << i.second << " "; cout << "\n";
	for (auto i : ptoc) cout << i.second << " "; cout << "\n";*/

	for (int r = 1; r <= L; ++r) {
		for (int c = 1; c <= L; ++c) {
			edge[ptor[{r, c}]].push_back(ptoc[{r, c}]);
		}
	}

	N = 10001;

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