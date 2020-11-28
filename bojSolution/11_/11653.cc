#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime[102000];
vector<ll> primes;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(isPrime, true, sizeof(isPrime));

	isPrime[1] = false;
	for (int i = 2; i <= 101000; ++i) {
		if (!isPrime[i]) continue;
		for (int j = 2 * i; j <= 101000; j += i) isPrime[j] = false;
	}
	for (ll i = 2; i <= 101000; ++i) if (isPrime[i]) primes.push_back((ll)i);

	ll n; cin >> n;

	for (int i = 0; i < primes.size(); ++i) {
		while (n % primes[i] == 0) {
			cout << primes[i] << "\n";
			n /= primes[i];
		}
	}
	if (n != 1) cout << n;
}