#include <bits/stdc++.h>
using namespace std;
struct Trie;
typedef pair<char, Trie*> pct;

struct Trie {
	vector<pct> child;
	bool protect, isRet;
	/*char mys;*/

	Trie() {
		protect = isRet = false;
	}
	~Trie() {
		for (auto c : child) delete c.second;
	}

	void insert(const char* key, bool forKeep) {
		if (forKeep) protect = true;
		if (*key == '\0') {
			if (!forKeep) isRet = true;
			return;
		}
		else {
			char next = *key;
			for (pct c : child) {
				if (c.first == next) {
					c.second->insert(key + 1, forKeep);
					return;
				}
			}
			child.push_back(pct(*key, new Trie));
			child.back().second->insert(key + 1, forKeep);
			/*child.back().second->mys = *key;*/
		}
	}

	int solve() {
		if (!protect) { /*cout << mys << "\n";*/ return 1; }
		int ret = isRet;

		for (pct c : child) {
			ret += c.second->solve();
		}

		return ret;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST;
	while (TEST--) {
		int N1, N2;
		Trie* root = new Trie;

		cin >> N1;
		for (int i = 0; i < N1; ++i) {
			string name; cin >> name;
			root->insert(name.c_str(), false);
		}

		cin >> N2;
		for (int i = 0; i < N2; ++i) {
			string name; cin >> name;
			root->insert(name.c_str(), true);
		}

		/*cout << "[root info] isRet: " << root->isRet << ", protect: " << root->protect << "\n";*/

		int req = root->solve();
		cout << req << "\n";

		delete root;
	}


	return 0;
}