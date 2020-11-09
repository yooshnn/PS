#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s, k; getline(cin, s); getline(cin, k);
	int i = 0;
	for (char& c : s) {
		if (c == ' ') cout << ' ';
		else cout << char((25 + (c - 'a') - (k[i % k.size()] - 'a')) % 26 + 'a');
		i++;
	}

	return 0;
}