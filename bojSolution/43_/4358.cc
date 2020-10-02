#include <bits/stdc++.h>
using namespace std;
const int childMax = 95;

int n;

struct Trie {
	Trie* child[childMax]; // ' ' ~ '~'
	double isRet;
	bool isParent;

	Trie() {
		fill(child, child + childMax, nullptr);
		isRet = 0.0;
		isParent = false;
	}
	~Trie() {
		for (int i = 0; i < childMax; ++i) {
			if (child[i]) delete child[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') isRet += 1.0;
		else {
			int next = *key - ' ';
			if (!child[next]) child[next] = new Trie;
			isParent = true;
			child[next]->insert(key + 1);
		}
	}

	void getRatio(string name) {
		if (isRet > 0) {
			cout << name << " " << isRet / static_cast<double>(n) * 100 << "\n";
		}
		for (int i = 0; i < childMax; ++i) {
			string cs = name + char(' ' + i);
			if (child[i]) child[i]->getRatio(cs);
		}
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout << fixed << setprecision(4);

	Trie* root = new Trie;
	string s;
	while (getline(cin, s)) {
		root->insert(s.c_str());
		n++;
	}
	root->getRatio("");

	delete root;

	return 0;
}