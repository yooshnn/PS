#include <bits/stdc++.h>
using namespace std;
struct Trie;
typedef pair<string, Trie*> pct;

struct Trie {
	map<string, Trie*> child;
	bool isRet;

	Trie() {
		isRet = false;
	}
	~Trie() {
		for (pct c : child) delete c.second;
	}

	void insert(vector<string> &v, int ind) {

		if (ind == v.size()) {
			isRet = true;
			return;
		}

		string k = v[ind];

		for (pct c : child) {
			if (c.first == k) {
				c.second->insert(v, ind + 1);
				return;
			}
		}

		child[k] = new Trie;
		child[k]->insert(v, ind + 1);
	}

	void demoFunc(string k, int depth) {
		if (depth >= 0) {
			for (int i = 0; i < depth; ++i) cout << "-";
			cout << k << "\n";
		}

		for (pct c : child) {
			c.second->demoFunc(c.first, depth + 2);
		}
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Trie* root = new Trie;
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		int antW; cin >> antW;
		vector<string> ant(antW);

		for (int w = 0; w < antW; ++w) cin >> ant[w];
		root->insert(ant, 0);
	}

	root->demoFunc("",-2);

	delete root;


	return 0;
}