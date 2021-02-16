#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int N, md = -1, pillar;

	cin >> N;
	ll p[N]; for (ll& x : p) cin >> x;

	for (int tar = 0; tar < N;) {
		int lp = tar-1, rp = tar+1, dest = -1, damage;
		ll w = 500;

		// +500 per a destruction
		while (dest != 0) {
			dest = 0;
			if (lp != -1 && p[lp] < 1000 + w) lp--, dest++;
			if (rp != N && p[rp] < 1000 + w) rp++, dest++;
			w += 500*dest;
		}
		damage = (rp-1) - (lp+1) + 1;

		if (damage > md) {
			md = damage;
			pillar = tar;
		}
		tar = rp;		
	}
	cout << md << " " << pillar;

}