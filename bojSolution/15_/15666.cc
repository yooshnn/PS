#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_set<string> dup;
int N, M;
vector<int> s;

void dfs(deque<int>& d, int idx, int depth) {
	d.push_back(s[idx]);
	if (depth == M - 1) {
		string res = "";
		for (int& i : d) {
			res.append(to_string(i) + " ");
		}
		if (dup.find(res) == dup.end()) {
			cout << res << "\n";
			dup.insert(res);
		}
	}
	else {
		for (int i = idx; i < N; ++i) {
			dfs(d, i, depth + 1);
		}
	}
	d.pop_back();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int input; cin >> input; s.push_back(input);
	}
	sort(s.begin(), s.end());

	deque<int> d;
	for (int i = 0; i < N; ++i) dfs(d, i, 0);

}