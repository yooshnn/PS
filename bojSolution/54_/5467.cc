#include <bits/stdc++.h>
using namespace std;
struct Trie;
typedef tuple<int, char, Trie*> tup;
typedef pair<char, Trie*> pct;

int last = 0;
vector<char> res;

struct compare {
	bool operator()(const tup& a, const tup& b) { return get<0>(a) > get<0>(b); }
};

struct Trie {
	vector<pct> child;
	int depth;
	bool isRet;

	Trie() {
		isRet = false; depth = 0;
	}
	~Trie() {
		for (pct c : child) delete c.second;
	}

	void insert(const char* key) {
		int k = *key;
		if (k == '\0') {
			isRet = true; return;
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

	int setDepth(int d) {
		if (child.size() == 0) {
			return depth = d;
		}
		for (pct c : child) {
			depth = max(depth, c.second->setDepth(d + 1));
		}
		return depth;
	}

	void ask() {
		if (isRet) {
			res.push_back('P');
			last = res.size();
		}
		priority_queue<tup, vector<tup>, compare > PQ;
		for (pct c : child) {
			PQ.push(tup{ c.second->depth, c.first, c.second });
		}
		while (!PQ.empty()) {
			char cc; Trie* cur;
			tie(std::ignore, cc, cur) = PQ.top(); PQ.pop();
			res.push_back(cc);
			cur->ask();
		}
		res.push_back('-');
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
	root->setDepth(0);
	root->ask();

	cout << last << "\n";
	for (int i = 0; i < last; ++i) {
		cout << res[i] << "\n";
	}

	delete root;


	return 0;
}