#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int indent[1002];
int moves[1002];
int N, res;

int sign(int x) {
	if (x == 0) return 0;
	return (x > 0 ? 1 : -1);
}

void calc(int p, int q) {
	/*cout << p << " to " << q << " : ";*/

	int* m;
	if (indent[p] > 0) m = min_element(indent + p, indent + q + 1);
	else m = max_element(indent + p, indent + q + 1);

	int d = *(*indent + m);
	res += abs(d);
	for (int i = p; i <= q; ++i) indent[i] -= d;

	//cout << p << ", " << q << abs(d) << endl;

	if (p == q) return;

	int z = -1;
	for (int i = p; i <= q; ++i) {
		if (indent[i] != 0) {
			if (z == -1) {
				z = i;
			}
		}
		if (indent[i] == 0) {
			if (z != -1) {
				calc(z, i - 1);
				z = -1;
			}
		}
		if (i == q && z != -1) {
			calc(z, i);
		}
	}
}

void solve() { // p <= x <= q
	int csign = sign(indent[1]), p = 1;
	for (int i = 1; i <= N; ++i) {
		if (csign != sign(indent[i])) {
			calc(p, i - 1);
			p = i;
			csign = sign(indent[i]);
		}
		if (i == N) {
			calc(p, i);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> indent[i];
	}
	for (int i = 1; i <= N; ++i) {
		int temp;
		cin >> temp;
		indent[i] = temp - indent[i];
	}
	/*for (int i = 1; i <= N; ++i) {
		cout << indent[i] << " ";
	}cout << endl;*/
	solve();

	cout << res;

	return 0;
}