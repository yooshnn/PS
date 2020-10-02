#include <bits/stdc++.h>
using namespace std;

int N, C, res;
int house[200000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; ++i) cin >> house[i];
	sort(house, house + N);

	int lower = 1, upper = house[N - 1] - house[0];

	while (lower <= upper) {
		int mid = (upper + lower) / 2;
		int pp = house[0], cnt = 1;
		for (int i = 1; i < N; ++i) {
			if (house[i] - pp >= mid) {
				pp = house[i];
				cnt++;
			}
		}
		/*cout << " @" << mid << " " << cnt << "\n";*/
		if (cnt >= C) {
			res = max(res, mid);
			lower = mid + 1;
		}
		else upper = mid - 1;
	}
	cout << res;

	return 0;
}