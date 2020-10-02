#include <bits/stdc++.h>
using namespace std; int TEST;
const int childMax = 10;

struct Trie {
	Trie* child[childMax]; // 0 ~ 9
	bool isRet, isParent;

	Trie() {
		fill(child, child + childMax, nullptr);
		isRet = isParent = false;
	}
	~Trie() {
		for (int i = 0; i < childMax; ++i) {
			if (child[i]) delete child[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') isRet = true;
		else {
			int next = *key - '0';
			if (!child[next]) child[next] = new Trie;
			isParent = true;
			child[next]->insert(key + 1);
		}
	}

	bool isConsistent() {
		if (isParent && isRet) return false;
		for (int i = 0; i < childMax; ++i)
			if (child[i] && !child[i]->isConsistent()) return false;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin >> TEST;

	while (TEST--) {
		int n; cin >> n;
		Trie* root = new Trie;
		for (int i = 0; i < n; ++i) {
			string tel; cin >> tel;
			root->insert(tel.c_str());
		}
		cout << (root->isConsistent() ? "YES" : "NO") << "\n";

		delete root;
	}

	return 0;
}