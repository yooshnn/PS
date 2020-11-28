#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
const int childMax = 26;
const char baseChar = 'a';

struct Trie {
	Trie* par;
	Trie* child[childMax];
	int g;

	Trie() {
		par = nullptr;
		fill(child, child + childMax, nullptr);
		g = 0;
	}
	~Trie() {
		for (int i = 0; i < childMax; ++i) {
			if (child[i]) delete child[i];
		}
	}

	Trie* insert(const char* key) {
		if (*key != '\0') {
			int next = *key - baseChar;
			if (!child[next]) {
				child[next] = new Trie;
				child[next]->par = this;
			}
			if (*(key + 1) == '\0') return this;
			return child[next]->insert(key + 1);
		}
	}

	void gameset() {
		for (Trie* c : child) if (c) c->gameset();
		calc();
	}

	void calc() {
		g = 0;
		for (Trie* c : child) if (c) g ^= c->g + 1;
		//cout << g << "\n";
	}

	bool game(const char* key) {
		Trie* t = insert(key);
		while (t->par) {
			t->calc();
			t = t->par;
		}
		t->calc();
		bool ret = t->g;
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TEST; cin >> TEST; for (int test = 1; test <= TEST; ++test) {
		Trie* root = new Trie;

		int n; string input;
		cin >> n; while (n--) {
			cin >> input;
			root->insert(input.c_str());
		} root->gameset();
		cin >> n; cout << "Case " << test << ":\n"; while (n--) {
			cin >> input;
			cout << 2 - int(root->game(input.c_str())) << "\n";
		}

		delete root;
	}

	return 0;
}