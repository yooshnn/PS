#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int N, M, J;
int lp, rp, res;
int apple[20];

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M >> J;
	lp = 1;
	rp = M;
	for (int i = 0; i < J; ++i) {
		cin >> apple[i];
	}

	for (int i = 0; i < J; ++i) {
		if (lp > apple[i]) {
			res += (lp - apple[i]);
			rp -= (lp - apple[i]);
			lp -= (lp - apple[i]);
		}
		else if (rp < apple[i]) {
			res += (apple[i] - rp);
			lp += (apple[i] - rp);
			rp += (apple[i] - rp);
		}
		/*for (int q = 1; q <= N; ++q) {
			if (q < lp) cout << "-";
			else if (q > rp) cout << "-";
			else if (q == apple[i]) cout << "A";
			else cout << "_";
		}cout << "\n";*/
	}

	cout << res;


	return 0;
}