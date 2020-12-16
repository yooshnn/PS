#include <bits/stdc++.h>
using namespace std;

int N, zc;
vector<int> vneg, vpos;
deque<int> dneg, dpos;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int t; cin >> t;
		if (t < 0) vneg.push_back(t);
		else if (t == 0) zc++;
		else vpos.push_back(t);
	}
	sort(vneg.begin(), vneg.end());
	sort(vpos.begin(), vpos.end());

	if (vneg.size() & 1) {
		for (int i = 0; i < vneg.size(); ++i) {
			if (i & 1) dneg.push_front(vneg[i]);
			else dneg.push_back(vneg[i]);
		}
	}
	else {
		for (int i = 0; i < vneg.size(); ++i) {
			if (i & 1) dneg.push_back(vneg[i]);
			else dneg.push_front(vneg[i]);
		}
	}

	if (vpos.size() & 1) {
		for (int i = vpos.size() - 1; i >= 0; --i) {
			if (i & 1) dpos.push_back(vpos[i]);
			else dpos.push_front(vpos[i]);
		}
	}
	else {
		for (int i = vpos.size() - 1; i >= 0; --i) {
			if (i & 1) dpos.push_back(vpos[i]);
			else dpos.push_front(vpos[i]);
		}
	}
	for (int& i : dneg) cout << i << " ";
	while (zc--) cout << 0 << " ";
	for (int& i : dpos) cout << i << " ";

}