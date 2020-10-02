#include <bits/stdc++.h>
using namespace std;

int n, res;
char parking[101];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> parking[i];
	for (int i = 1; i <= n; ++i) {
		char input; cin >> input;
		if (parking[i] == 'C' && input == 'C') res++;
	}
	cout << res;
	return 0;
}