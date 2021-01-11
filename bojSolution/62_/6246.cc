#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	int N, Q; cin >> N >> Q;
	vector<int> balloon(N, 0);
	while (Q--) {
		int i, j; cin >> i >> j;
		i--;
		while (i < N) {
			balloon[i] = 1;
			i += j;
		}
	}
	cout << N-accumulate(balloon.begin(), balloon.end(), 0);

    return_0;
}