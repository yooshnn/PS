#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<short int>v;
double aa;
short int ma = -4001, mi = 4001;

int mode() {
	if (N == 1) return v[0];

	int freq[8002];
	int count = 1, maxcount = 1, res = -9999;

	memset(freq, 0, sizeof(freq));
	freq[4000 + v[0]] = 1;
	for (int i = 1; i < N; ++i) {
		freq[4000 + v[i]]++;
		if (v[i] == v[i - 1]) {
			maxcount = max(maxcount, ++count);
		}
		else {
			count = 1;
		}
	}
	for (int i = mi; i <= ma; ++i) {
		if (freq[4000 + i] == maxcount) {
			if (res == -9999) res = i;
			else return i;
		}
	}
	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		short int input;
		cin >> input;
		aa += input;
		v.push_back(input);
		ma = max(input, ma);
		mi = min(input, mi);
	}

	sort(v.begin(), v.end());
	cout << (int)round(aa / N) << "\n";
	cout << v[N / 2] << "\n";
	cout << mode() << "\n";
	cout << ma - mi;

	return 0;
}