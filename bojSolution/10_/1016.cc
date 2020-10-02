#include <iostream>
#define ll long long
using namespace std;

bool arr[1000001];
ll l, r;

int main() {
	cin >> l >> r;

	for (ll i = 2; i * i <= r; ++i) {
		ll s = ((l - 1) / (i * i) + 1) * (i * i);
		for (ll j = s; j <= r; j += i * i) {
			arr[j - l] = true;
		}
	}

	ll res = 0;
	for (ll i = 0; i <= r - l; ++i) {
		if (arr[i] == 0) res++;
	}

	cout << res;

	return 0;
}