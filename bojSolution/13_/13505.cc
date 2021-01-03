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
			int next = *key - baseChar;
			if (!child[next]) child[next] = new Trie;
			isParent = true;
			child[next]->insert(key+1);
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

};

ll fastpow(ll a, ll b) {
	ll ret = 1;

	while (b > 0) {
		if (b & 1) ret = (ret * a), b -= 1;
		else a = (a * a), b >>= 1;
	}

	return ret;
}

string toBin(int t) {
	string ret(30, '0');
	for (int i = 29; i >= 0; --i) {
		ret[i] = ((t&1) ? '1' : '0');
		t >>= 1;
	}
	return ret;
}
int toDec(string& t) {
	int ret = 0;
	for (int i = 29; i >= 0; --i) {
		ret += (t[i]-'0') * fastpow(2, 29-i);
	}
	return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	Trie T;
	int N; cin >> N;
	string num[N];

	for (int i = 0, t; i < N; ++i) {
		cin >> t; num[i] = toBin(t);
		T.insert(&num[i][0]);
	}

	int res = 0;
	for (int i = 0; i < N; ++i) {
		T.query(&num[i][0]);
		res = max(res, toDec(num[i]));
	}
	
	cout << res;

    return_0;
}