#include <bits/stdc++.h>
using namespace std;
// const int childMax = 26;
// const char baseChar = 'A';
struct Trie;
typedef pair<char, Trie*> pct;
typedef long long ll;

long long modulo = 1000000007;
priority_queue<string> names;

ll f[30]{ 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 227020758, 178290591, 674358851, 789741546, 425606191, 660911389, 557316307, 146326063, 72847302, 602640637, 860734560, 657629300, 440732388, 459042011, 394134213, 35757887, 36978716 };

struct Trie {
	vector<pct> child;
	// Trie* child[childMax]; // 'A' ~ 'Z'
	//bool isRet, isParent;
	int childCnt;

	Trie() {
		childCnt = 0;
	}

	void insert(const char* key) {
		if (*key == '\0') {
			childCnt++;
			return;
		}
		else {
			int next = *key;
			for (pct c : child) {
				if (c.first == next) {
					c.second->insert(key + 1);
					return;
				}
			}
			childCnt++;
			child.push_back(pct(*key, new Trie));
			child[child.size() - 1].second->insert(key + 1);
		}
	}

	ll sanggeunSort() {
		if (childCnt == 0) return 1;
		ll ret = f[childCnt];
		for (pct c : child) ret = ret * c.second->sanggeunSort() % modulo;
		return ret;
	}
};

int LCP(string s1, string s2) {
	for (int i = 0; i < s1.length(); i++) {
		if (i == s2.length() || s2[i] != s1[i]) {
			return i;
		}
	}
	return s1.length();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	Trie* root = new Trie;
	for (int i = 0; i < n; ++i) {
		string name; cin >> name;
		root->insert(name.c_str());
	}

	cout << root->sanggeunSort();

	delete root;


	return 0;
}