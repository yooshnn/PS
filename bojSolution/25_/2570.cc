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

const int MAX = 1200;
int N, K, A[MAX], B[MAX];

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

bool block[100][100];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i = 0, r, c; i < M; ++i) {
        cin >> r >> c;
        block[r][c] = true;
    }

    map<pii, int> xx, yy;
    int ir, ic, uid = 0;
    bool refresh;

    for (ir = 1; ir < 2*N; ++ir) {
        ic = max(1, ir-N+1);
        refresh = true;
        for (int r = min(N, ir), c = ic; r > 0 && c <= N; --r, ++c) {
            if (block[r][c]) refresh = true;
            else {
                if (refresh) uid++;
                refresh = false;
                xx[{r, c}] = uid;
            }
        }
    }
    uid = 0;
    for (ic = 1; ic < 2*N; ++ic) {
        ir = min(N, 2*N-ic);
        refresh = true;
        for (int c = min(N, ic), r = ir; r > 0 && c > 0; --r, --c) {
            if (block[r][c]) refresh = true;
            else {
                if (refresh) uid++;
                refresh = false;
                yy[{r, c}] = uid;
            }
        }
    }

    for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) if (!block[r][c]) edge[xx[{r, c}]].push_back(yy[{r, c}]);

	int match = 0;
	fill(A + 1, A + MAX - 1, -1);
	fill(B + 1, B + MAX - 1, -1);
	for (int i = 1; i < MAX; i++) {
		if (A[i] == -1) {
			fill(visited + 1, visited + MAX - 1, 0);
			if (dfs(i))match++;
		}
	}
	cout << match;

    return_0;
}