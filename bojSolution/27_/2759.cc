#include <bits/stdc++.h>
using namespace std; int TEST;

int N;
int cake[31];
vector <int> res;

void flip(int n) {
	res.push_back(n);
	reverse(cake + 1, cake + n + 1);
}

void pancake(int n) {
	if (n == 1) return;

	int t = find(cake, cake + n, n) - cake;

	if (t == n) pancake(n - 1);
	else if (t == 1) {
		flip(n);
		pancake(n - 1);
	}
	else {
		flip(t);
		flip(n);
		pancake(n - 1);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0); cin >> TEST;
	
	while (TEST--) {

		res.clear();

		cin >> N;
		for (int i = 1; i <= N; ++i) cin >> cake[i];

		if (N == 0) continue;

		pancake(N);

		cout << res.size() << " ";
		for (int i : res) cout << i << " ";
		cout << "\n";

	}

	return 0;
}