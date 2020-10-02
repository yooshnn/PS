#include <bits/stdc++.h>
using namespace std;
struct Trie;
typedef pair<char, Trie*> pct;

struct Trie {
	vector<pct> child;
	bool isCol, isNick;

	Trie() {
		isCol = false;
		isNick = false;
	}
	~Trie() {
		for (pct c : child) delete c.second;
	}

	void insert(const char* key, int type) {
		int k = *key;
		if (k == '\0') {
			(type == 1 ? isCol : isNick) = true;
			return;
		}

		for (pct c : child) {
			if (c.first == k) {
				c.second->insert(key + 1, type);
				return;
			}
		}

		child.push_back(pct(*key, new Trie));
		child.back().second->insert(key + 1, type);
	}

	void getCols(const char* key, vector<int>& cv, int depth) {
		int k = *key;
		if (isCol) {
			cv.push_back(depth);
		}
		if (k == '\0') return;

		for (pct c : child) {
			if (c.first == k) c.second->getCols(key + 1, cv, depth + 1);
		}
		return;
	}

	bool isLegendary(const char* key, vector<int>& cv, int depth, int len) {
		int k = *key;
		if (isNick) {
			if (find(cv.begin(), cv.end(), len - depth) != cv.end()) return true;
		}
		if (k == '\0') return false;

		for (pct c : child) {
			if (c.first == k) return c.second->isLegendary(key + 1, cv, depth + 1, len);
		}

		return false;
	}

};

int C, N, Q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Trie* info = new Trie;

	cin >> C >> N;

	for (int i = 0; i < C; ++i) {
		string input; cin >> input;
		info->insert(input.c_str(), 1);
	}
	for (int i = 0; i < N; ++i) {
		string input; cin >> input;
		reverse(input.begin(), input.end());
		info->insert(input.c_str(), 2);
	}

	cin >> Q;

	for (int i = 0; i < Q; ++i) {
		vector<int> cols;

		string input; cin >> input;
		info->getCols(input.c_str(), cols, 0);
		reverse(input.begin(), input.end());
		cout << (info->isLegendary(input.c_str(), cols, 0, input.length()) ? "Yes" : "No") << "\n";
	}

	delete info;

	return 0;
}