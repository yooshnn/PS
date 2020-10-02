#include <bits/stdc++.h>
using namespace std;// int TEST;
const int childMax = 26;

int N;
double res;

struct Trie {
	Trie* child[childMax]; // a ~ z
	bool isRet, isParent, isRoot;
	int cCnt;

	Trie() {
		fill(child, child + childMax, nullptr);
		isRet = isParent = isRoot = false;
		cCnt = 0;
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
			if (!child[next]) {
				child[next] = new Trie;
				cCnt++;
			}
			isParent = true;
			child[next]->insert(key + 1);
		}
	}

	void getWords(double r) {
		if (cCnt == 0) {
			res += r;
			// cout << "@ " << r << "\n";
			return;
		}
		if (isRet) {
			res += r;
			// cout << "@ " << r << "\n";
		}
		for (int i = 0; i < childMax; ++i) {
			if (child[i]) {
				child[i]->getWords(r + (!isRoot && (cCnt > 1 || isRet)));
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);// cin >> TEST;

	cout << fixed;
	cout.precision(2);

	while (cin >> N) {
		Trie* root = new Trie;
		root->isRoot = true;
		res = 0;

		for (int i = 0; i < N; ++i) {
			string s; cin >> s;
			root->insert(s.c_str());
		}

		root->getWords(1);
		cout << res / N << "\n";

		delete root;
	}

	return 0;
}