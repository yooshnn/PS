#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sushi[26];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N; while (N--) {
		string s; cin >> s;
		for (char c : s) sushi[c - 'A'] += 1;
	}

	int res = 0;
	for (int i = 0; i < 26; ++i) res += sushi[i];

	cout << res;
}