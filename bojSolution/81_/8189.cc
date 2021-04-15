#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

bool pp(char a, char b) {
  if (a=='_' || b=='_') return false;
  return ((a=='#' && b=='#') || (a != b));
}

ll manacher(string& src) {
  ll rets = 0;
	ll srcLen = src.size(); src.resize(srcLen * 2 + 1, '#');
	for (int i = srcLen - 1; i >= 0; --i) src[i * 2 + 1] = src[i], src[i] = '#';
  src[0] = src[src.size()-1] = '_';

	ll c = 0, r = 0, len = src.size();
	vector<ll> ret(len, 0);
	for (int i = 2; i < len - 1; i += 2) {
		ll sym = 2 * c - i;
		if (i < r) ret[i] = min(r - i, ret[sym]);
		while (i - ret[i] > 0 && i + ret[i] - 1 < len && pp(src[i - ret[i] - 1], src[i + ret[i] + 1])) ret[i]++;
		if (ret[i] + i > r) r = ret[i] + i, c = i;
    rets += (ret[i] + 1) / 2;
	}

  // for (char c : src) cout << c << " "; cout << endl;
  // for (int i : ret) cout << i << " "; cout << endl;

	return rets;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  string s; cin >> s >> s;
  cout << manacher(s);
}