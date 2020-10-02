#include <bits/stdc++.h>
using namespace std;
struct Trie;
typedef pair<char, Trie*> pct;

struct Trie {
	vector<pct> child;
	bool isRet;

	Trie() {
		isRet = false;
	}
	~Trie() {
		for (pct c : child) delete c.second;
	}

	void insert(const char* key) {
		int k = *key;
		if (k == '\0') {
			isRet = true;
			return;
		}

		for (pct c : child) {
			if (c.first == k) {
				c.second->insert(key + 1);
				return;
			}
		}

		child.push_back(pct(*key, new Trie));
		child.back().second->insert(key + 1);
	}

	bool demoFunc(const char* key) {
		int k = *key;
		if (isRet && k == '\0') return true;
		
		for (pct c : child) {
			if (c.first == k) return c.second->demoFunc(key + 1);
		}

		return false;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Trie* root = new Trie;
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		string input; cin >> input;
		root->insert(input.c_str());
	}

	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		string input; cin >> input;
		cout << (root->demoFunc(input.c_str()) ? "YES" : "NO") << "\n";
	}

	delete root;


	return 0;
}
