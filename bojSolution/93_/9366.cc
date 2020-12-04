#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TEST; cin >> TEST; for (int test = 1; test <= TEST; ++test) {
		vector<int> s(3); for (auto& i : s) cin >> i;
		sort(s.begin(), s.end());
		cout << "Case #" << test << ": ";
		if (s[2] >= s[0] + s[1]) cout << "invalid!";
		else if (s[0] == s[1] && s[0] == s[2]) cout << "equilateral";
		else if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) cout << "isosceles";
		else cout << "scalene";
		cout << "\n";
	}
}