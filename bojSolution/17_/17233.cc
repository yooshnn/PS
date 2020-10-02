#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int T; set<string> tar; vector<int> tarLen;
int srcLen; string src;

unordered_map<int, int> visit;

vector<int> fail;
vector<vector<int>> locs;

void getFail(string t) {
	fail.resize(0); fail.resize(t.length(), 0);
	int j = 0;
	for (int i = 1; i < t.length(); ++i) {
		while (j > 0 && t[i] != t[j]) j = fail[j - 1];
		if (t[i] == t[j]) fail[i] = ++j;
	}
}

void getKMP(string s, string t, int id) {
	int sLen = s.length(), tLen = t.length(), j = 0;

	for (int i = 0; i < sLen; ++i) {
		while (j > 0 && s[i] != t[j]) j = fail[j - 1];
		if (s[i] == t[j]) {
			if (j == tLen - 1) {
				locs[i - tLen + 1].push_back(id);
				j = fail[j];
			}
			else j++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	for (int t = 0; t < T; ++t) {
		int l; string s; cin >> l >> s;
		tar.insert(s);
	} T = tar.size(); tarLen.resize(T);

	cin >> srcLen >> src;
	locs.resize(srcLen);

	int id = 0;
	for (auto t : tar) {
		getFail(t);
		tarLen[id] = t.length();
		getKMP(src, t, id++);
	}

	int lp = 0, rp = -1, cnt = 0, dist = 0, res = 2147483647;
	while (lp < srcLen) {
		if (cnt < T) {
			rp++;
			if (rp >= srcLen) break;
			for (int id : locs[rp]) {
				if (visit[id] == 0) {
					cnt++;
					dist = max(dist, rp + tarLen[id]);
				}
				visit[id]++;
			}
		}
		else {
			for (int id : locs[lp]) {
				visit[id]--;
				if (visit[id] == 0) {
					cnt--;
				}
			}
			lp++;
			if (lp >= srcLen) break;
		}
		//cout << "[" << lp << " " << rp << "] " << cnt << "\n";
		if (cnt == T) res = min(res, dist - lp);
	}

	cout << res;

	/*id = 0;
	for (auto loc : locs) {
		cout << id << " / ";
		for (auto i : loc) cout << i << " (" << tarLen[i] << "), ";
		cout << "\n";
	}*/

	return 0;
}