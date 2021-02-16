#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	string s; cin >> s;
	int len = s.size()/3;

	for (int i = 0; i <= 1; ++i) {
		for (int j = i+1; j <= 2; ++j) {
			if (s.substr(i*len, len) == s.substr(j*len, len)) {
				cout << s.substr(i*len, len);
				return 0;
			}
		}
	}
}