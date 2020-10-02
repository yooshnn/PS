#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	int streak = 1, res = 0; 
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] - s[i - 1] == 1) streak++;
		else streak = 1;
		if (streak == 3) {
			if (i == s.size() - 1) res++;
			else if (s[i + 1] - s[i] != 1) res++;
		}
	}
	cout << res;

	return 0;
}