#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

int M, b, r;
vector<int> bucket;

void solve(int i, int t) {
	if (t > M) return;
	if (i == b) {
		r = max(r, t);
		return;
	}
	solve(i+1, t);
	solve(i+1, t + bucket[i]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> M >> b;
	bucket.resize(b);

	for (int& x : bucket) cin >> x;

	solve(0, 0);
	solve(0, bucket[0]);

	cout << r;

    return_0;
}