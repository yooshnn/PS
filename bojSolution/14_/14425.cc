#include <bits/stdc++.h>
using namespace std;// int TEST;
const int childMax = 26;

struct Trie {
	Trie* child[childMax]; // a ~ z
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
			int next = *key - 'a';
			if (!child[next]) child[next] = new Trie;
			isParent = true;
			child[next]->insert(key + 1);
		}
	}

	bool isInSet(const char* key) {
		if (*key == '\0') return isRet;
		else {
			int next = *key - 'a';
			if (!child[next]) return false;
			return child[next]->isInSet(key + 1);
		}
	}
};

int N, M, res;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);// cin >> TEST;

	Trie* root = new Trie;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string s; cin >> s;
		root->insert(s.c_str());
	}
	for (int i = 0; i < M; ++i) {
		string s; cin >> s;
		res += (root->isInSet(s.c_str()) ? 1 : 0);
	}

	cout << res;

	return 0;
}