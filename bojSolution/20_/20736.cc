#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    
	int N, res = 1e8; cin >> N;
	vector<int> v(N);
	for (int& x : v) cin >> x;

	for (int i = 0; i < N; ++i) {
		res = min(res, v[i] + v[(i+2)%N]);
	}
	cout << res;
    
}