#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

const int childMax = 2;
const char baseChar = '0';

struct Trie {
	Trie* child[childMax];
	int w;
	bool isRet;

	Trie() {
		fill(child, child + childMax, nullptr);
		w = 0;
		isRet = false;
	}

	void insert(const char* key) {
		if (*key == '\0') isRet = true;
		else {
			int next = *key - baseChar;
			if (!child[next]) child[next] = new Trie;
			child[next]->w += 1;
			child[next]->insert(key+1);
		}
	}
	void erase(const char* key) {
		if (*key == '\0') return;
		else {
			int next = *key - baseChar;
			child[next]->w -= 1;
			child[next]->erase(key+1);
			if (child[next]->w == 0) {
				delete child[next];
				child[next] = nullptr;
			}
		}
	}

	void query(char* key) {
		if (*key == '\0') return;
		else {
			int next = *key - baseChar;
			next ^= 1;
			if (child[next]) {
				*key = '1';
				child[next]->query(key+1);
			}
			else {
				*key = '0';
				child[next^1]->query(key+1);
			}
		}
	}

	bool exists(char* key) {
		if (*key == '\0') return isRet;
		else {
			int next = *key - baseChar;
			if (!child[next]) return false;
			return child[next]->exists(key + 1);
		}
	}

};

ll fastpow(ll a, ll b) {
	ll ret = 1;
	while (b > 0) {
		if (b & 1) ret = (ret * a), b -= 1;
		else a = (a * a), b >>= 1;
	} return ret;
}
string toBin(int t) {
	string ret(30, '0');
	for (int i = 29; i >= 0; --i) {
		ret[i] = ((t&1) ? '1' : '0');
		t >>= 1;
	} return ret;
}
int toDec(string& t) {
	int ret = 0;
	for (int i = 29; i >= 0; --i) {
		ret += (t[i]-'0') * fastpow(2, 29-i);
	} return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	Trie T; T.insert(toBin(0).c_str());
	map<int, int> pp;
	int Q; cin >> Q; while (Q--) {
		int oper, x; cin >> oper >> x;
		if (oper == 1) {
			if (pp[x] == 0) {
				T.insert(toBin(x).c_str());
			}
			pp[x] += 1;
		}
		else if (oper == 2) {
			pp[x] -= 1;
			if (pp[x] == 0) {
				T.erase(toBin(x).c_str());
			}
		}
		else {
			string s = toBin(x);
			// cout << (T.exists(&s[0]) ? "YES" : "NO") << endl;
			T.query(&s[0]);
			cout << toDec(s) << "\n";
		}
	}

    return_0;
}