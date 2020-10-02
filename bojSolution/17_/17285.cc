#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string T; cin >> T;
	int key = T[0]^'C';

	for (char c : T) cout << char(int(c) ^ key);

	return 0;
}