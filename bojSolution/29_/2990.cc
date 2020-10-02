#include <bits/stdc++.h>
using namespace std;
struct Trie;
typedef pair<char, Trie*> pct;

int N, Q;
int found = -1;

struct Trie {
	vector<pct> child;
	int visit, cnt;
	bool isRet;

	Trie() {
		visit = 0; cnt = 0;
		isRet = false;
	}
	~Trie() {
		for (pct c : child) delete c.second;
	}

	void insert(const char* key, int pp, int len) {
		int k = *key; visit += 1;
		if (k == '\0') { /*cout << pp << " ";*/ cnt = pp + len; isRet = true; return; }

		for (pct c : child) {
			if (c.first == k) {
				c.second->insert(key + 1, pp + c.second->visit, len);
				return;
			}
		}

		child.push_back(pct(*key, new Trie));
		child.back().second->insert(key + 1, pp + child.back().second->visit, len);
	}

	int ask(const char* key, int len) {
		int k = *key, ret = 0;
		if (isRet && k == '\0') {
			found = (cnt); return 0;
		}
		else if (isRet) {
			ret += len;
		}

		for (pct c : child) {
			if (found >= 0) return 0;
			if (c.first == k) ret += c.second->ask(key + 1, len + 1);
			else ret += (len) * c.second->visit;
		}

		return ret;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Trie* root = new Trie;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		string input; cin >> input;
		root->insert(input.c_str(), 0, input.length() + 1 + i);
	}
	root->visit = 0;

	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		string input; cin >> input;
		int req = root->ask(input.c_str(), 1);
		cout << (found == -1 ? req : found) << "\n";
		found = -1;
	}

	delete root;

	return 0;
}