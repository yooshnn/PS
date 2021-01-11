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

	int n; cin >> n;
	vector<int> par(n+1, -1);
	vector<int> dup(n+1, 1e8);

	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, n});
	while (!que.empty()) {
		int i, t; tie(i, t) = que.top(); que.pop();
		if (t == 1) continue;
		if (t % 3 == 0 && dup[t/3]>i+1) que.push({i+1, t/3}), par[t/3] = t, dup[t/3]=i+1;
		if (t % 2 == 0 && dup[t/2]>i+1) que.push({i+1, t/2}), par[t/2] = t, dup[t/2]=i+1;
		if (dup[t-1]>i+1) que.push({i+1, t-1}), par[t-1] = t, dup[t-1]=i+1;
	}

	int t = 1;
	vector<int> res;
	while (t != -1) {
		res.push_back(t);
		t = par[t];
	}
	cout << res.size()-1 << "\n";
	for (int i = res.size()-1; i >= 0; --i) cout << res[i] << " ";

    return_0;
}