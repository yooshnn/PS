#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int s[1004000];

void seive() {
	s[1] = true;
	for (int n = 2; n <= 502001; ++n) {
		if (s[n]) continue;
		for (int i = 2; n * i < 1004000; ++i) {
			s[n * i] = true;
		}
	}
}

bool palindrome(int x) {
	int p[7]; int i = 0;
	while (x) {
		p[i] = x % 10;
		x /= 10;
		i++;
	}
	for (int j = 0; j < i / 2; ++j) {
		if (p[j] != p[i - 1 - j]) return false;
	}
	return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	seive();
	
	int n; cin >> n;
	while (s[n] || !palindrome(n)) {
		n++;
	}

	cout << n;
	
	// cout << endl; system("pause");
}