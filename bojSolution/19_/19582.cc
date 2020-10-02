#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <queue>
#include <deque>
#include <tuple>
using namespace std;

int N;
long long prize[100001];
long long limit[100001];

bool case1, case2, case3;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> limit[i] >> prize[i];
	}


	long long m = 0;
	long long mp = 0;
	bool skipped = false;

	for (int i = 0; i < N; ++i) {
		if (limit[i] < m) {
			break;
		}
		m += prize[i];
		if (i == N - 1) case1 = true;
	}

	m = 0;
	mp = 0;
	skipped = false;

	for (int i = 0; i < N; ++i) {
		if (limit[i] < m) {
			if (!skipped) {
				m -= mp;
				skipped = true;
				if (limit[i] < m) {
					break;
				}
			}
			else {
				break;
			}
		}
		m += prize[i];
		if (prize[i] > mp) mp = prize[i];
		if (i == N - 1) case2 = true;
	}

	m = 0;
	mp = 0;
	skipped = false;

	for (int i = 0; i < N; ++i) {
		if (limit[i] < m) {
			if (!skipped) {
				if (i == N - 1) case3 = true;
				skipped = true;
				continue;
			}
			else {
				break;
			}
		}
		m += prize[i];
		if (i == N - 1) case3 = true;
	}

	/*cout << case1 << " " << case2 << " " << case3 << "\n";*/

	cout << ((case1 || case2 || case3) ? "Kkeo-eok" : "Zzz");
	return 0;
}