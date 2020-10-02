#include <iostream>
#define ll long long
using namespace std;

ll lan[10000];
int K, N;
ll lp, rp, mp, lanCnt, res;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> K >> N;
	for (int i = 0; i < K; ++i) {
		cin >> lan[i];
	}

	lp = 0;
	rp = 2147483647;

	while (lp <= rp) {
		mp = (lp + rp) / 2;
		lanCnt = 0;
		for (auto item : lan) lanCnt += item / mp;

		if (lanCnt >= N) {
			lp = mp + 1;
			if (mp > res) res = mp;
		}
		else {
			rp = mp - 1;
		}
	}

	cout << res;


	return 0;
}