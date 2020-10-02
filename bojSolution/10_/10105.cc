#include <bits/stdc++.h>
using namespace std;

bool good = true;
int n;

map<string, int> m;
vector<int> status;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	status.resize(n, -1);

	for (int i = 0; i < n; ++i) {
		string t; cin >> t;
		m[t] = i;
	}
	for (int i = 0; i < n; ++i) {
		string t; cin >> t;
		int req = m[t];
		if (req == i) good = false;
		if (status[req] == -1) status[i] = req;
		else {
			if (status[req] == i) continue;
			good = false;
		}
	}

	cout << (good ? "good" : "bad");

	return 0;
}