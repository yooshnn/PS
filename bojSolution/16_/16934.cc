#include <bits/stdc++.h>
using namespace std;
const int childMax = 26;
const char baseChar = 'a';

struct Trie {
	Trie* child[childMax]; // 'A' ~ 'Z'
	bool isRet;
	int enc;

	Trie() {
		fill(child, child + childMax, nullptr);
		isRet = false;
		enc = 0;
	}

	int insert(const char* key, int len, int ret) {
		if (*key == '\0') {
			enc--;
			if (ret == 0) return enc;
			return ret;
		}
		else {
			int next = *key - baseChar;
			if (!child[next]) {
				if (ret == 0) ret = len;
				child[next] = new Trie;
			}
			return child[next]->insert(key + 1, len + 1, ret);
		}
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	Trie* root = new Trie;
	for (int i = 0; i < n; ++i) {
		string name; cin >> name;
		int req = root->insert(name.c_str(), 1, 0);
		if (req > 0) {
			for (int c = 0; c < req; ++c) cout << name[c];
			cout << "\n";
		}
		else {
			if (req != -1) cout << name << req * -1;
			else cout << name;
			cout << "\n";
		}
	}


	return 0;
}